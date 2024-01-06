#include<iostream>
#include<string>
#include<cstring>
#include<vector>

/**
 * 右值引用详解
 * 包含std::move的使用详解
*/
class MyString {
    private:
        char* _data;
        size_t _len;
        void _init_data(const char* s) {
            _data = new char[_len + 1];
            memcpy(_data, s, _len);
            _data[_len] = '\0';
        }

    public:
        MyString() {
            _data = nullptr;
            _len = 0;
        }

        MyString(const char* p) {
            std::cout<< "Constructor MyString(const char* p)!" << std::endl;
            _len = strlen(p);
            _init_data(p);
        }

        // 复制构造函数
        MyString(const MyString& obj) {
            _len = obj._len;
            _init_data(obj._data);
            std::cout << "Copy Constructor is called! source: " << obj._data << std::endl;
        }

        MyString(MyString&& obj) {
            std::cout << "Move Constructor is called! source: " << obj._data << std::endl;
            _len = obj._len;
            _data = obj._data;

            obj._len = 0;
            // !防止在析构函数中将内存释放掉
            obj._data = nullptr;

        }

        // 运算符重载=
        MyString& operator=(const MyString& obj) {
            if (this != &obj) {
                _len = obj._len;
                _init_data(obj._data);
            }
            std::cout << "Copy Assignment is called! source: " << obj._data << std::endl;
            return *this;
        }

        // ，使用右值引用，运算符重载=
        MyString& operator=(MyString&& obj) {
            std::cout << "Move Assignment is called! source: " << obj._data << std::endl;
            if (this != &obj) {
                _len = obj._len;
                _data = obj._data; // 转移_data，没有重新开辟内存
                
                // 释放原obj内容
                obj._len = 0;

                // 防止在析构函数中将内存释放掉，不释放原来的内存, 即不调用free函数，只是将内容指向空
                obj._data = nullptr; 
            }

            return *this;
        }

        ~MyString() {
            if (_data != nullptr) {

                free(_data);
            }
            std::cout << "Destuctor is called! " << std::endl;
        }

        void print() {
            std::cout << "data is : " << _data << std::endl;
        }
};


// template<class T>
// void swap(T& a, T& b) {
//     T tmp(a);
//     a = b;
//     b = tmp;
// }

// 若变为如下方式，减少了临时对象的创建
template <class T>
void swap(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}



int main() {

    // MyString a = MyString("Hello"); // 调用一次构造函数
    // MyString a; 
    // a = MyString("Hello"); // 调用一次构造函数创建MyString("hello"),再调用赋值构造函数创建a，调用两次


    // 使用move就没有初始化数据，开辟内存再拷贝的操作。
    // std::vector<MyString> vec;
    // vec.push_back(std::move(MyString("Hello.")));

    MyString a = MyString("123");
    MyString b = MyString("abc");

    b.print();
    swap(a, b);
    b.print();

    return 0;
}