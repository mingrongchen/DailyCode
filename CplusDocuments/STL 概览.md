# STL概览


STL（Standard Template Library）是C++的标准模板库，提供了一组通用的模板类和函数，涵盖了诸多常见的数据结构和算法。STL 的核心组件包括容器（Containers）、算法（Algorithms）、迭代器（Iterators）、函数对象（Function Objects）和算法适配器（Adapters）。以下是STL的主要组成部分和一些常用的功能：

### 1. 容器（Containers）

STL 提供了多种容器类，可以方便地存储和管理数据。常见的容器包括：

- **vector**: 动态数组。
- **list**: 双向链表。
- **deque**: 双端队列。
- **queue**: 队列。
- **stack**: 栈。
- **set**: 有序集合。
- **map**: 有序映射。
- **unordered_set**: 无序集合。
- **unordered_map**: 无序映射。

```c++
cppCopy code#include <iostream>
#include <vector>
#include <map>

int main() {
    // 使用 vector 存储整数
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用 map 存储键值对
    std::map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 2;

    return 0;
}
```

### 2. 算法（Algorithms）

STL 包含了丰富的算法，用于处理容器中的数据。这些算法包括排序、查找、遍历等。

```c++
cppCopy code#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // 对容器进行排序
    std::sort(vec.begin(), vec.end());

    // 遍历容器并输出
    for (int num : vec) {
        std::cout << num << " ";
    }

    return 0;
}
```

### 3. 迭代器（Iterators）

迭代器提供了对容器元素的访问方式，分为输入迭代器、输出迭代器、前向迭代器、双向迭代器和随机访问迭代器。

```c++
cppCopy code#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用迭代器访问容器元素
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

### 4. 函数对象（Function Objects）

函数对象是可以像函数一样被调用的对象，可以通过重载函数调用运算符`()`实现。

```c++
cppCopy code#include <iostream>
#include <vector>
#include <algorithm>

// 函数对象
struct MultiplyBy {
    int factor;

    MultiplyBy(int factor) : factor(factor) {}

    int operator()(int x) const {
        return x * factor;
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用函数对象进行变换
    MultiplyBy multiplyBy2(2);
    std::transform(vec.begin(), vec.end(), vec.begin(), multiplyBy2);

    // 输出变换后的容器
    for (int num : vec) {
        std::cout << num << " ";
    }

    return 0;
}
```

### 5. 算法适配器（Adapters）

STL 提供了一些算法适配器，用于修改或包装其他算法的行为。常见的适配器包括 `std::reverse_iterator`、`std::back_inserter`、`std::bind` 等。

```c++
cppCopy code#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> reversedVec;

    // 使用 reverse_iterator 适配器逆序遍历容器
    std::copy(vec.rbegin(), vec.rend(), std::back_inserter(reversedVec));

    // 输出逆序后的容器
    for (int num : reversedVec) {
        std::cout << num << " ";
    }

    return 0;
}
```

这只是STL的一小部分功能，STL 提供了丰富的工具，可以在C++中进行高效而灵活的编程。深入理解STL可以提高代码的可读性和效率。