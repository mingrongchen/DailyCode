#include<iostream>
#include<string>

class CData {
    public:
        CData(const char* ch) : data(ch) {
            std::cout << "CData(const char* ch) " << std::endl;
        }

        // 左值引用构造函数
        CData(const std::string& str) : data(str) {    
            std::cout << "CData(const std::string& str) " << std::endl;
        }

        // 右值引用构造函数
        CData(const std::string&& str) : data(str) {
            std::cout << "CData(std::string&& str) " << std::endl;
        }

        ~CData() {
            std::cout << "~CData() " << std::endl;
        }

    private:
        std::string data;
};

// 定义一个模板新建函数
/**
 * 如果T是string类型，则入参可以是string，string&，string&&，模板有折叠规则：
 * tring&  &&折叠之后是string&
 * string&&  &&折叠之后是string&&
 * string &&折叠后是string&
 * 
 * 如果定义是CData* Creator(T& t)
 * string& &折叠之后是string&
 * string&& &折叠之后是string& 注意这个
 * string &折叠后是string&
*/
template<typename T>
CData* Creator(T&& t) {

    // 如果是右值，期望传递右值引用，则使用std::forward()
    // std::forward作用是将传入的参数原封不动的传递到下一个函数中
    return new CData(std::forward<T>(t));
}



int main() {
    const char* value = "hello";
    std::string str1 = "hello";
    std::string str2 = "world";
    std::string& str3 = str2;
    std::string&& str4 = str1 + str2;

    std::cout << "左值" << std::endl;
    // 1、CData(const std::string& str), 传进去的str1是个左值地址
    CData* p1 = Creator(str1); 
    delete p1;

    std::cout << "右值" << std::endl;
    //CData(const std::string& str),内容相加是个右值
    CData* p2 = Creator(str1 + str2);
    delete p2;

    std::cout << "右值引用，也是个左值" << std::endl;
    // CData(const std::string& str)
    CData* p3 = Creator(str3);
    delete p3;

    std::cout << "右值引用，也是一个左值" << std::endl;
    // CData(const std::string& str)
    // CData* p4 = Creator(str4);
    // 注意str4是个右值引用，但是是个左值，需要传递右值时，用std::move一下
    CData* p4 = Creator(std::move(str4));
    delete p4;

    return 0;
}