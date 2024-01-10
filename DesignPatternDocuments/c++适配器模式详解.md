# c++适配器模式详解

适配器模式（Adapter Pattern）是一种结构性设计模式，它允许接口不兼容的类能够一起工作。适配器模式通过引入一个适配器来实现这种兼容性，该适配器将一个类的接口转换成客户端所期望的接口。适配器模式常用于以下场景：

1. 将一个已经存在的类的接口与系统中期望的接口不一致时。
2. 在使用第三方库或模块时，需要将其接口适配成符合自己系统要求的接口。

以下是适配器模式的详细解释：

### 1. 类适配器模式

类适配器模式使用多重继承，同时继承目标接口和被适配的类。

```c++
cppCopy code#include <iostream>

// 目标接口
class Target {
public:
    virtual void request() const = 0;
};

// 被适配的类
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Specific request from Adaptee." << std::endl;
    }
};

// 适配器类
class Adapter : public Target, public Adaptee {
public:
    void request() const override {
        specificRequest();
    }
};

int main() {
    Target* target = new Adapter();
    target->request();

    delete target;
    return 0;
}
```

### 2. 对象适配器模式

对象适配器模式使用组合，将被适配的类的实例作为适配器的一个成员。

```c++
cppCopy code#include <iostream>

// 目标接口
class Target {
public:
    virtual void request() const = 0;
};

// 被适配的类
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Specific request from Adaptee." << std::endl;
    }
};

// 适配器类
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

int main() {
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    target->request();

    delete adaptee;
    delete target;
    return 0;
}
```

### 3. 适配器模式的应用场景

- **接口不兼容：** 当系统中的一个类的接口与其他类的期望接口不一致时，可以使用适配器模式来适配这个类，使得它们能够一起工作。
- **旧接口与新接口转换：** 当需要使用已存在的类，但其接口不符合需求时，适配器可以将其接口转换成符合要求的接口。
- **与第三方库或模块集成：** 当引入一个新的库或模块，而其接口与系统已有的接口不匹配时，可以使用适配器模式进行接口转换，以便顺利集成。

### 4. 适配器模式的优缺点

#### 优点：

- **灵活性：** 适配器模式使得系统更加灵活，能够适应不同接口的类协同工作。
- **复用性：** 可以重用现有的类，而不需要修改其代码。

#### 缺点：

- **类适配器的限制：** 类适配器模式要求被适配的类必须是具体类，而不是抽象类或接口。
- **适配器与被适配者紧密耦合：** 在适配器模式中，适配器与被适配者的代码是紧密关联的，一旦被适配者的接口发生变化，适配器也需要调整。

适配器模式在软件设计中有着广泛的应用，尤其在整合不同模块或引入第三方库时，它能够使得系统更具扩展性和复用性。