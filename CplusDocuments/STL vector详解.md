# STL vector详解

`std::vector` 是 C++ 标准模板库（STL）中的一个动态数组容器，提供了动态大小的数组，并且可以在常量时间内访问元素。以下是关于 `std::vector` 的详细解释：

### 1. 包含头文件

使用 `std::vector` 需要包含 `<vector>` 头文件。

```c++
cppCopy code#include <iostream>
#include <vector>
```

### 2. 创建和初始化 `std::vector`

```c++
cppCopy code// 创建一个空的 vector
std::vector<int> emptyVector;

// 创建并初始化 vector
std::vector<int> myVector = {1, 2, 3, 4, 5};
```

### 3. 访问元素

可以使用下标或迭代器访问 `std::vector` 的元素。

```c++
cppCopy code// 使用下标访问元素
int elementAtIndex = myVector[2];

// 使用迭代器访问元素
std::vector<int>::iterator it = myVector.begin();
std::cout << "First element: " << *it << std::endl;
```

### 4. 插入和删除元素

```c++
cppCopy code// 在末尾插入元素
myVector.push_back(6);

// 在开头插入元素
myVector.insert(myVector.begin(), 0);

// 删除末尾元素
myVector.pop_back();

// 删除指定位置的元素
myVector.erase(myVector.begin() + 2);
```

### 5. 获取容器大小和清空容器

```c++
cppCopy code// 获取容器大小
std::cout << "Size: " << myVector.size() << std::endl;

// 清空容器
myVector.clear();
```

### 6. 遍历容器

```c++
cppCopy code// 使用迭代器遍历
for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
    std::cout << *it << " ";
}

// 使用范围-based for 循环遍历
for (int element : myVector) {
    std::cout << element << " ";
}
```

### 7. 容器排序

```c++
cppCopy code// 对容器进行升序排序
std::sort(myVector.begin(), myVector.end());

// 对容器进行降序排序
std::sort(myVector.begin(), myVector.end(), std::greater<int>());
```

### 8. 判断容器是否为空

```c++
cppCopy codeif (myVector.empty()) {
    std::cout << "Vector is empty." << std::endl;
} else {
    std::cout << "Vector is not empty." << std::endl;
}
```

### 9. 获取首尾元素

```c++
cppCopy code// 获取首元素
int firstElement = myVector.front();

// 获取尾元素
int lastElement = myVector.back();
```

### 10. 使用迭代器进行插入和删除

```c++
cppCopy code// 在指定位置插入元素
myVector.insert(myVector.begin() + 2, 10);

// 在指定位置删除元素
myVector.erase(myVector.begin() + 1);
```

### 11. 容器的复制

```c++
cppCopy code// 复制构造函数
std::vector<int> copiedVector(myVector);

// 赋值操作符
std::vector<int> assignedVector = myVector;
```

`std::vector` 是 C++ 中非常实用的容器，支持动态大小的数组操作，适用于大多数动态数组的需求。了解如何使用 `std::vector` 可以让你更高效地处理动态数组，并提高代码的可读性和维护性。