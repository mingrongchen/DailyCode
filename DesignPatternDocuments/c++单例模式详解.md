# c++单例模式详解


单例模式是一种创建型设计模式，它确保一个类只有一个实例，并提供一个全局访问点。单例模式主要解决以下问题：

1. **全局唯一性：** 确保一个类只有一个实例。
2. **全局访问：** 提供一个全局访问点，让其他类能够访问该实例。

在 C++ 中，实现单例模式的方式有多种，以下是一种基于懒汉式的线程安全的单例模式的实现：

```c++
cppCopy code#include <iostream>
#include <mutex>

class Singleton {
private:
    // 私有的构造函数，确保外部无法直接实例化
    Singleton() {}

    // 禁用拷贝构造和赋值运算符
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance;  // 静态成员变量，用于保存唯一实例
    static std::mutex mutex;    // 互斥锁，确保多线程安全

public:
    // 获取唯一实例的静态成员函数
    static Singleton* getInstance() {
        // 懒汉式，使用双检锁保证线程安全
        if (instance == nullptr) {
            std::unique_lock<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    // 其他成员函数
    void showMessage() const {
        std::cout << "Singleton instance message." << std::endl;
    }
};

// 初始化静态成员变量
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;

int main() {
    // 获取单例实例
    Singleton* singleton = Singleton::getInstance();

    // 使用单例实例
    singleton->showMessage();

    return 0;
}
```

上述代码中，通过懒汉式的方式实现了线程安全的单例模式。值得注意的是，使用 `std::mutex` 来确保在多线程环境下对单例对象的创建是安全的。另外，将拷贝构造函数和赋值运算符声明为私有的，以防止通过拷贝或赋值的方式创建多个实例。

在实际应用中，也可以考虑使用 Meyers' Singleton（静态局部变量）或使用 `std::call_once` 等方式来实现线程安全的单例。选择哪种方式取决于具体需求和性能要求。