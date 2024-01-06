#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>

/**
 * 原子操作用法
*/
std::atomic<int> shared_data(0);

void func() {
    for (int i = 0; i < 1000000; i++)
    {
        shared_data++;
    }
    
}

int main() {

    // 当前时间
    auto last = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    std::cout << shared_data << std::endl;
    auto cur = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();

    std::cout << cur - last << std::endl;
    return 0;
}