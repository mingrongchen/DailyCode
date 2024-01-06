#include<iostream>
#include<thread>
#include<mutex>

int shared_data = 0;
// std::mutex mtx;
std::timed_mutex mtx;

// //lock_guard use
// void func() {
//     for (int i = 0; i < 1000000; i++)
//     {
//         std::lock_guard<std::mutex> lg(mtx);
//         shared_data += 1;
//     }
    
// }

/*unique_lock
*
*/
void func() {
    for (int i = 0; i < 10; i++)
    {
        std::unique_lock<std::timed_mutex> lg(mtx, std::defer_lock);

        if (lg.try_lock_for(std::chrono::seconds(1)))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
            shared_data += 1;
        }
        
    }
    
}

int main() {
    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    std::cout << shared_data << std::endl;

    return 0;
}