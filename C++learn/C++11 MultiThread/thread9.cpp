#include<iostream>
#include<thread>
#include<string>
#include<mutex>
#include<condition_variable>
#include<functional>
#include<future>

#include<vector>
#include<queue>


/**
 * 异步编程
*/


// int func() {
//     int i = 0;
//     for (i = 0; i < 1000; i++)
//     {
//         std::cout<< "func" << std::endl;
//     }

//     return i;  
// }

void func(std::promise<int> &f) {
    f.set_value(1000); 
}

int main() {
    // // 2、packaged_task使用方法，封装成成一个packaged_task对象
    // std::packaged_task<int()> task(func);

    // auto future_result = task.get_future();

    // // 为什么要用move，task是一个可移动对象，放到线程中执行需要move来转移一下
    // std::thread t1(std::move(task));
    // t1.join();

    // // 1、future运行用法
    // // std::future<int> future_result = std::async(std::launch::async, func);
    // std::cout << func() << std::endl;

    // std::cout << future_result.get() << std::endl;


    // promise用法
    std::promise<int> f;
    auto future_result = f.get_future();
    // std::thread t1(func, std::move(f));

    // 使用promise引用，而不是拷贝构造，效率高
    std::thread t1(func, std::ref(f));
    t1.join();

    std::cout << future_result.get() << std::endl;

    return 0;
}