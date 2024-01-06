#include<iostream>
#include<thread>
#include<mutex>

int a = 0;
std::mutex m1, m2;


void func_1() {
    for (size_t i = 0; i < 200; i++)
    {
        m1.lock();
        m2.lock();
        m1.unlock();
        m2.unlock();   
    }
    
 
}

void func_2() {
    for (size_t i = 0; i < 200; i++)
    {
        m2.lock();
        m1.lock();
        m1.unlock();
        m2.unlock(); 
    }
    
   
}

int main() {
    std::thread t1(func_1);
    std::thread t2(func_2);

    t1.join();
    t2.join();

    std::cout << "over ..." << std::endl;

    return 0;
}