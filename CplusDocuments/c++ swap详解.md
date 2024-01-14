# c++ swap详解

`std::swap` 是 C++ 标准库中的一个函数，用于交换两个值。这个函数的目的是提供一种通用的、高效的方式来进行值的交换，而不需要手动创建临时变量。

`std::swap` 的声明位于头文件 `<utility>` 中，并且在命名空间 `std` 中。其基本语法如下：

```c++
cppCopy codenamespace std {
    template <class T>
    void swap(T& a, T& b);
}
```

这里 `T` 是模板参数，表示任意类型。`std::swap` 接受两个引用参数 `a` 和 `b`，它们是需要交换的值的引用。

下面是一个简单的例子，演示如何使用 `std::swap`：

```c++
cppCopy code#include <iostream>
#include <utility>

int main() {
    int x = 5, y = 10;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    std::swap(x, y);

    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
```

这个程序将输出：

```c++
mathematicaCopy codeBefore swap: x = 5, y = 10
After swap: x = 10, y = 5
```

`std::swap` 函数通过引用传递参数，因此可以用于交换各种类型的值，包括基本数据类型、用户定义的类型和标准库容器等。

要注意的是，C++11 引入了对移动语义的支持，`std::swap` 在某些情况下可以通过移动而不是复制来提高性能。这对于处理大型数据结构时可能很有用。

总的来说，`std::swap` 是一个方便且通用的函数，可以用于进行值的快速交换。