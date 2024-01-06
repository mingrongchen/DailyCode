#include <iostream>
#include<thread>
#include<string>
#include<memory>

// std::thread t;

void foo(int* x) {

    std::cout<<*x<<std::endl;
}

// void test() {
//     int a = 1;

//     t = std::thread(foo, std::ref(a));
// }

void printHelloWorld(std::string msg) {

    std::cout << msg << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout<<i<<std::endl;
    }
    

    return;
}

class A {
    friend void thread_foo();

    private:
    void foo() {
        std::cout<<"Hello" <<std::endl;
    }
};

void thread_foo() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::thread t(&A::foo, a);;
    t.join();
}

int main() {

    std::cout<<"before .."<<std::endl;

    thread_foo();

    std::cout<<"end .."<<std::endl;

    return 0;
}