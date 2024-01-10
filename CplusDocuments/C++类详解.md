# C++ 类详解



在 C++ 中，类（Class）是一种用户自定义的数据类型，用于封装数据和行为。类提供了一种创建用户定义类型的机制，它是面向对象编程（OOP）的基础。以下是关于 C++ 类的详细解释：

### 1. 类的定义

使用 `class` 关键字来定义类，类的定义通常包含在头文件（.h）中。

```c++
cppCopy code// Point.h

#ifndef POINT_H
#define POINT_H

class Point {
public:
    // 成员变量
    int x;
    int y;

    // 成员函数声明
    void setCoordinates(int newX, int newY);
    void printCoordinates();
};

#endif // POINT_H
```

### 2. 类的实现

实现类的成员函数，通常在对应的源文件（.cpp）中。

```c++
cppCopy code// Point.cpp

#include "Point.h"
#include <iostream>

// 成员函数的定义
void Point::setCoordinates(int newX, int newY) {
    x = newX;
    y = newY;
}

void Point::printCoordinates() {
    std::cout << "x: " << x << ", y: " << y << std::endl;
}
```

### 3. 类的使用

在程序中包含类的头文件，并使用类的对象来调用成员函数。

```c++
cppCopy code// main.cpp

#include "Point.h"

int main() {
    // 创建类的对象
    Point p1;

    // 调用成员函数
    p1.setCoordinates(10, 20);
    p1.printCoordinates();

    return 0;
}
```

### 4. 成员变量和成员函数

- **成员变量：** 类中的数据成员，用于存储对象的状态。
- **成员函数：** 类中的函数成员，用于操作对象的行为。

```c++
cppCopy codeclass MyClass {
public:
    // 成员变量
    int myInt;

    // 成员函数声明
    void printInt();
};

// 成员函数的定义
void MyClass::printInt() {
    std::cout << "myInt: " << myInt << std::endl;
}
```

### 5. 访问控制

类的成员可以有不同的访问权限，包括 `public`、`private` 和 `protected`。默认情况下，类的成员是 `private` 的。

```c++
cppCopy codeclass MyClass {
private:
    int privateVar;

public:
    int publicVar;

    // ...
};
```

### 6. 构造函数和析构函数

- **构造函数（Constructor）：** 类的特殊成员函数，在对象创建时被调用，用于初始化对象的状态。

```c++
cppCopy codeclass MyClass {
public:
    // 构造函数
    MyClass() {
        // 初始化操作
    }
};
```

- **析构函数（Destructor）：** 类的特殊成员函数，在对象销毁时被调用，用于释放资源。

```c++
cppCopy codeclass MyClass {
public:
    // 析构函数
    ~MyClass() {
        // 清理操作
    }
};
```

### 7. 静态成员

静态成员是类的成员，它属于类而不是对象。静态成员在类的所有对象中共享。

```c++
cppCopy codeclass MyClass {
public:
    // 静态成员变量
    static int staticVar;

    // 静态成员函数
    static void staticFunction();
};

// 静态成员变量的定义
int MyClass::staticVar = 0;

// 静态成员函数的定义
void MyClass::staticFunction() {
    std::cout << "Static Function" << std::endl;
}
```

### 8. 成员初始化列表

在构造函数中使用成员初始化列表初始化成员变量。

```c++
cppCopy codeclass MyClass {
private:
    int x;
    int y;

public:
    // 构造函数使用成员初始化列表
    MyClass(int newX, int newY) : x(newX), y(newY) {
        // 构造函数的其他操作
    }
};
```

### 9. 友元函数和友元类

通过友元函数和友元类，可以授权其他类或函数访问当前类的私有成员。

```c++
cppCopy codeclass MyClass {
private:
    int privateVar;

    // 友元函数声明
    friend void friendFunction(MyClass& obj);

    // 友元类声明
    friend class FriendClass;
};

// 友元函数的定义
void friendFunction(MyClass& obj) {
    obj.privateVar = 42;
}

// 友元类的定义
class FriendClass {
public:
    void accessPrivateVar(MyClass& obj) {
        obj.privateVar = 100;
    }
};
```

这些是 C++ 中类的基本概念和使用方法。类是面向对象编程中的重要概念，它允许将数据和行为组织成一个独立的单元，提高代码的模块化和可维护性。