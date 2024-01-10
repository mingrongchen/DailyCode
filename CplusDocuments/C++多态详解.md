# C++ 多态详解

多态（Polymorphism）是面向对象程序设计中的一个重要概念，它允许一个接口被多个类实现，或者一个基类指针指向不同派生类的对象，以实现在运行时选择不同的实现。在 C++ 中，多态主要通过虚函数（virtual function）和抽象类（abstract class）来实现。

### 1. 虚函数

在基类中声明一个虚函数，允许派生类提供对应的实现。使用 `virtual` 关键字进行声明。

```c++
cppCopy codeclass Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};
```

### 2. 虚析构函数

当基类拥有虚函数时，通常需要为其声明虚析构函数，以确保在删除指向派生类对象的基类指针时正确调用析构函数。

```c++
cppCopy codeclass Shape {
public:
    virtual ~Shape() {
        std::cout << "Shape destructor." << std::endl;
    }

    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};
```

### 3. 纯虚函数和抽象类

纯虚函数是没有实现的虚函数，用 `= 0` 表示。包含纯虚函数的类称为抽象类，无法创建该类的对象，但可以通过指向派生类对象的指针或引用来实现多态。

```c++
cppCopy codeclass Shape {
public:
    virtual ~Shape() {}

    virtual void draw() const = 0;
};
```

### 4. 多态的实现

通过基类指针或引用指向派生类对象，可以在运行时选择调用不同的实现。

```c++
cppCopy codeint main() {
    Shape* shapePtr;

    Circle circle;
    Square square;

    shapePtr = &circle;
    shapePtr->draw();  // 调用派生类 Circle 的 draw 函数

    shapePtr = &square;
    shapePtr->draw();  // 调用派生类 Square 的 draw 函数

    return 0;
}
```

### 5. 虚函数表（vtable）

在实现多态的过程中，编译器通常会为每个包含虚函数的类生成一个虚函数表。虚函数表是一个指向虚函数地址的指针数组，用于在运行时动态调用正确的函数。

### 6. 虚函数的限制

- 虚函数不能是静态成员函数。
- 构造函数不能是虚函数，析构函数可以是虚函数。
- 虚函数不能是友元函数。

多态是面向对象程序设计中的一个重要概念，它提高了代码的灵活性和可维护性。通过虚函数和抽象类的使用，可以在编写代码时更加注重接口而非实现细节。