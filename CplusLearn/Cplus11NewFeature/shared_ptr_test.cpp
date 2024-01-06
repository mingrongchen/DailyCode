#include<iostream>
#include<memory>

class Test {
    public:
        Test() {
            std::cout << "Test() constructor ..." << std::endl;
        }

        ~Test() {
            std::cout << "~Test() constructor ..." << std::endl;
        }
};



int main() {
    std::shared_ptr<Test> p1 = std::make_shared<Test>();  // 新建内存，构造Test对象
    std::cout << " 1 ref: " << p1.use_count() << std::endl;

    {
        std::shared_ptr<Test> p2 = p1; // 创建新的引用，count变为2，指向同一个对象
        std::cout << " 2 ref: " << p2.use_count() << std::endl;
    }
    // p2 销毁，count变为1
    std::cout << " 2 ref: " << p1.use_count() << std::endl;

    return 0;
}