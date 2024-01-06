#include<iostream>
#include<memory>


class TestB;

class TestA {
    public:
        TestA() {
            std::cout << "TestA constructor ..." << std::endl;
        }

        void ReferTestB(std::shared_ptr<TestB> test_ptr) {
            m_TestB_Ptr = test_ptr;   // 弱引用指向，计数器没有加
        }

        void TestWork() {
            std::cout << "TestA::TestWork()" << std::endl;
        }

        ~TestA() {
            std::cout << "~TestA() constructor ..." << std::endl;
        }


    private:
        std::weak_ptr<TestB> m_TestB_Ptr;
};

class TestB {
    public:
        TestB() {
            std::cout << "TestB() constructor ..." << std::endl;
        }

        void ReferTestA(std::shared_ptr<TestA> test_ptr) {
            m_TestA_Ptr = test_ptr;
        }

        void TestWork() {
            std::cout << "~TestB::TestWork() ..." << std::endl;
        }

        ~TestB() {
            // 将A类的弱引用转换为强引用，对象A的count加一等于2
            std::shared_ptr<TestA> tmp = m_TestA_Ptr.lock();
            tmp->TestWork();
            std::cout << "2 ref a: " << tmp.use_count() << std::endl;
            std::cout << "~TestB() " << std::endl;
        }
    

    private:
        std::weak_ptr<TestA> m_TestA_Ptr;
};

int main() {
    std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>(); // 创建强引用A
    std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>(); // 创建强引用B

    ptr_a->ReferTestB(ptr_b); //A类里面的弱引用指向B
    ptr_b->ReferTestA(ptr_a); //B类里面的弱引用指向A

    std::cout << "1 ref a: " << ptr_a.use_count() << std::endl;
    std::cout << "1 ref b: " << ptr_a.use_count() << std::endl;


    return 0;
}