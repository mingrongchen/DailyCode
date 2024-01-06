#include<iostream>
#include<thread>
#include<string>
#include<mutex>
#include<condition_variable>
#include<functional>

#include<vector>
#include<queue>

#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))


class ThreadPool {

    public:
    ThreadPool(int numThreads) : stop(false) {
        for (int i = 0; i < numThreads; i++)
        {
            // push_back加成员时会拷贝构造，emplace_back加任务直接调用成员类型的构造函数，节约资源
            threads.emplace_back([this] {
                while(1) {
                    std::unique_lock<std::mutex> lock(mtx);

                    // 判断队列里面有没有任务，有的话就取一个任务去完成，
                    condition.wait(lock, [this] {
                        // 队列为空时，线程池终止时
                        return !tasks.empty() || stop;
                    });

                    // 线程池终止时返回
                    if (stop && tasks.empty()) {
                        return;
                    }

                    // 取任务,move作用可以将一个左值转换成右值引用，从而调用c++11右值引用的拷贝
                    // 构造函数，在对象拷贝的使用，不会产生一行代码原先的对象也会清空，可以减少支援的创建和释放
                    std::function<void()> task(std::move(tasks.front()));
                    tasks.pop();
                    lock.unlock();

                    // 执行任务
                    task();
                }
            }); 
        }
    } // end

    ~ThreadPool() {

        {
            std::unique_lock<std::mutex> lock(mtx);
            stop = true;
        }

        condition.notify_all();
        // 清空任务队列，将所有任务执行完成
        for (auto& t : threads)
        {
            t.join();
        }
         
    } // end

    // 函数模板里面，&&是万能引用，左值则取左值，右值则取右值
    template<class F,class... Args>
    void enqueue(F &&f, Args&&... args) {
        // 可以将bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成新的可调用对象来适应原对象的参数列表。
        std::function<void()> task = 
            std::bind(std::forward<F>(f), std::forward<Args>(args)...);


        {
            std::unique_lock<std::mutex> lock(mtx);
            // 如果是左值的话，转换成右值传进去
            tasks.emplace(std::move(task));
        }
        
        condition.notify_one();
    }
        
    private:
    // 线程数组，任务队列
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable condition;

    bool stop;

};



int main() {

    ThreadPool pool(4);

    for (int i = 0; i < 10; i++)
    {
        pool.enqueue([i]{
            std::cout << "task : " << i << " is running " <<std::endl;
            sleep(1000);
            std::cout << "task : " << i << " is done " << std::endl;
        });
    }
    

    return 0;
}