#include<iostream>
#include<functional>

#define PI 6

class Test {
    public:

        Test() {}
        typedef int(*FunType)(int, int);

        void Add(std::function<int(int, int)> fun, int a, int b) {
            std::cout << "Add functional ..." << std::endl;
            int sum = fun(a, b);
            std::cout << "sum : " << sum << std::endl;
        }   

        // void Add(FunType fun, int a, int b) {
        //     std::cout << "function point ..." << std::endl;
        //     int sum = fun(a, b);
        //     std::cout << "sum: " << sum << std::endl;
        // }


};

int add(int a, int b) {
    return a + b;
}

int main() {
    std::cout << PI << std::endl;
    Test test;
    test.Add(std::move(add), 1, 2);

    return 0;
}
