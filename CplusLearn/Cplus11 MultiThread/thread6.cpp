#include<iostream>
#include<thread>
#include<mutex>

static Log *log = nullptr; // 懒汉模式
std::once_flag once;
class Log {
    public:
    Log() {};
    Log(const Log& log) = delete;
    Log& operator=(const Log& log) = delete;

    static Log& GetInstance() {
        // static Log log; // 懒汉模式
        std::call_once(once, init);
    
        return *log;
    }

    static void init() {
        if (!log) log = new Log;  
    }

    void PrintLog(std::string msg) {
        std::cout << __TIME__<< ' '<< msg << std::endl;
    }

private:


};

void print_error() {
    Log::GetInstance().PrintLog("error");
}

int main() {
    
    std::thread t1(print_error);
    std::thread t2(print_error);

    t1.join();
    t2.join();

    return 0;
}