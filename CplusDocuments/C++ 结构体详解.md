# C++ 结构体详解

在 C++ 中，结构体（struct）是一种用户自定义的数据类型，用于将不同类型的数据组合在一起。结构体与类（class）相似，但默认的成员访问权限是公共的。以下是关于 C++ 结构体的详细解释：

### 1. 定义结构体

使用 `struct` 关键字来定义结构体。结构体中可以包含不同类型的成员变量，也可以包含成员函数。

```c++
cppCopy code// 定义一个简单的结构体
struct Point {
    int x;
    int y;
};

// 使用结构体
Point p1;  // 创建结构体变量
p1.x = 10;  // 访问结构体成员
p1.y = 20;
```

### 2. 结构体初始化

可以使用不同的方式初始化结构体变量：

```c++
cppCopy code// 使用成员初始化列表
Point p2 = {5, 15};

// 使用默认构造函数
Point p3{};
```

### 3. 结构体成员访问

可以使用成员访问运算符 `.` 来访问结构体的成员。

```c++
cppCopy code
int distance = sqrt(p1.x * p1.x + p1.y * p1.y);
```

### 4. 结构体作为参数和返回值

结构体可以作为函数的参数和返回值。

```c++
cppCopy code// 结构体作为参数
void printPoint(Point p) {
    cout << "x: " << p.x << ", y: " << p.y << endl;
}

// 结构体作为返回值
Point createPoint(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
```

### 5. 结构体中的函数

结构体中可以包含成员函数，这些函数可以用于操作结构体的数据。

```c++
cppCopy codestruct Rectangle {
    int width;
    int height;

    // 计算面积的成员函数
    int calculateArea() {
        return width * height;
    }
};

// 使用结构体及其成员函数
Rectangle r1 = {5, 10};
int area = r1.calculateArea();
```

### 6. 结构体的嵌套

结构体可以嵌套在其他结构体中，形成复杂的数据结构。

```c++
cppCopy codestruct Address {
    string street;
    string city;
    string zipCode;
};

struct Person {
    string name;
    int age;
    Address address;  // 结构体的嵌套
};

Person person1 = {"John Doe", 25, {"123 Main St", "Cityville", "12345"}};
```

### 7. 结构体与类的区别

- 结构体的成员默认是公共的，而类的成员默认是私有的。
- 在结构体中，成员函数可以有默认实现（C++11 及之后的版本支持）。
- 结构体和类在语法上非常相似，主要区别在于默认的成员访问权限。

### 8. C++11 中的新特性

从 C++11 开始，结构体可以包含构造函数、析构函数等特性，与类更加接近。例如：

```c++
cppCopy codestruct Point {
    int x;
    int y;

    // 构造函数（C++11 及以后版本支持）
    Point(int x, int y) : x(x), y(y) {}
};
```

总体而言，结构体在 C++ 中提供了一种轻量级的数据组织方式，适用于简单的数据结构。在一些情况下，结构体也可以用于创建对象，而不仅仅是用于组织数据。