# STL函数对象详解

函数对象（Function Objects）是一种可调用对象，即可以像函数一样被调用。C++中的函数对象可以通过函数指针、函数对象类、Lambda表达式等方式实现。函数对象常用于STL算法、标准库中，以及一些需要自定义行为的场景。以下是有关C++函数对象的详细解释：

### 1. **函数对象类**

通过定义一个类，并在该类中重载调用运算符`operator()`，实现函数对象。

```c++
cppCopy code#include <iostream>

// 函数对象类
struct Add {
    int operator()(int a, int b) const {
        return a + b;
    }
};

int main() {
    Add addFunction;

    // 使用函数对象
    int result = addFunction(3, 4);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

### 2. **函数指针**

函数指针可以指向一个函数，通过函数指针实现函数对象的效果。

```c++
cppCopy code#include <iostream>

// 函数
int addFunction(int a, int b) {
    return a + b;
}

int main() {
    // 函数指针
    int (*addPtr)(int, int) = &addFunction;

    // 使用函数指针
    int result = addPtr(3, 4);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

### 3. **Lambda 表达式**

Lambda 表达式是C++11引入的一种匿名函数的语法，可以用来创建临时的函数对象。

```c++
cppCopy code#include <iostream>

int main() {
    // Lambda 表达式
    auto addLambda = [](int a, int b) {
        return a + b;
    };

    // 使用 Lambda 表达式
    int result = addLambda(3, 4);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

### 4. **标准库中的函数对象**

C++标准库提供了一些常用的函数对象，位于 `<functional>` 头文件中，例如 `std::plus`、`std::minus`、`std::multiplies` 等。

```c++
cppCopy code#include <iostream>
#include <functional>

int main() {
    std::plus<int> addFunction;

    // 使用标准库中的函数对象
    int result = addFunction(3, 4);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

### 5. **STL 算法中的函数对象**

STL（Standard Template Library）中的算法通常接受函数对象作为参数，例如 `std::sort`、`std::transform` 等。

```c++
cppCopy code#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // 使用函数对象进行排序
    std::sort(numbers.begin(), numbers.end(), std::less<int>());

    // 使用函数对象进行变换
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), [](int x) {
        return x * 2;
    });

    // 输出结果
    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

函数对象在C++中是一个非常灵活和强大的概念，它可以帮助实现一些复杂的行为，并且在STL算法和标准库中得到广泛应用。