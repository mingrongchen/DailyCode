#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<condition_variable>

#include<vector>
#include<queue>
/**
 * 线程池的实现
*/

#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

std::queue<int> g_queue;
std::condition_variable g_cv;
std::mutex mtx;

void Producer() {
    for (int i = 0; i < 10; i++)
    {

        {
            std::unique_lock<std::mutex> lock(mtx);
            g_queue.push(i);
                
            // 任务产生时，告知消费者
            g_cv.notify_one();   // 通知一个线程去取
    
            std::cout << "Producer : " << i << std::endl;

        }
        
        sleep(100);        
    } // for end
    
}


void Consumer() {
    while (1)
    {
        std::unique_lock<std::mutex> lock(mtx);

        // 任务队列为空时，等待,不取任务.不为空时
        g_cv.wait(lock, [](){return !g_queue.empty();
            });

        int value = g_queue.front();
        g_queue.pop();

        std::cout << "Consumer : " << value << std::endl;
    }
    
}


int main () {
    std::thread t1(Producer);
    std::thread t2(Consumer);

    t1.join();
    t2.join();

    return 0;
}