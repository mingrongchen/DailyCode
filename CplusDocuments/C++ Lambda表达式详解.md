# C++ Lambda表达式详解

Lambda 表达式是 C++11 引入的一种匿名函数语法，允许在代码中定义一个简短的、临时的函数对象。Lambda 表达式的基本语法如下：

```
cppCopy code[capture](parameters) -> return_type {
    // lambda body
}
```

其中：

- `capture`：捕获列表，用于捕获外部变量。可以为空，也可以是：
  - `[]` 表示不捕获任何外部变量。
  - `[x, y]` 表示捕获 `x` 和 `y`。
  - `[&x, y]` 表示捕获 `x` 的引用，而 `y` 通过值捕获。
  - `[=]` 表示捕获所有外部变量通过值。
  - `[&]` 表示捕获所有外部变量通过引用。
- `parameters`：形式参数列表，与普通函数的参数列表类似。
- `return_type`：返回类型，可以省略，根据 lambda 的内容自动推导。
- `lambda body`：lambda 函数体。

以下是一些具体的 Lambda 表达式的示例：

### 1. Lambda 表达式基本用法

```c++
cppCopy code#include <iostream>

int main() {
    // 简单的 Lambda 表达式，不捕获任何外部变量
    auto simpleLambda = []() {
        std::cout << "Hello, Lambda!" << std::endl;
    };

    // 调用 Lambda 函数
    simpleLambda();

    return 0;
}
```

### 2. 捕获外部变量

```c++
cppCopy code#include <iostream>

int main() {
    int x = 5;
    int y = 3;

    // 捕获外部变量 x 和 y
    auto captureLambda = [x, &y]() {
        std::cout << "Captured variables: x = " << x << ", y = " << y << std::endl;
    };

    // 调用 Lambda 函数
    captureLambda();

    return 0;
}
```

### 3. 返回值

```c++
cppCopy code#include <iostream>

int main() {
    // Lambda 表达式返回值
    auto addLambda = [](int a, int b) -> int {
        return a + b;
    };

    // 调用 Lambda 函数
    int result = addLambda(3, 4);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

### 4. 使用标准库算法和 Lambda 表达式

```c++
cppCopy code#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // 使用 Lambda 表达式进行排序
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });

    // 输出排序结果
    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

Lambda 表达式是 C++ 中非常灵活和强大的特性，它允许在需要简短函数时直接在代码中定义，提高了代码的可读性和简洁性。Lambda 表达式通常在需要传递函数对象作为参数的地方或需要局部定义函数对象的地方被广泛应用。