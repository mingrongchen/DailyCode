#include<iostream>


class Test {
    public: 
        void test_work(int index){
            std::cout << "test_work 1" << std::endl;
        }

        void test_work(int* index) {
            std::cout << "test_work 2" << std::endl;
        }
};


int main() {
    Test test;

    test.test_work(NULL);   // 编译器报错，NULL ambiguous
    test.test_work(nullptr);

    return 0;
}