# STL list总结

`std::list` 是 C++ 标准模板库（STL）中的一个双向链表容器，提供了在两个方向上快速插入和删除元素的能力。以下是关于 `std::list` 的一些基本知识：

### 1. 包含头文件

使用 `std::list` 需要包含 `<list>` 头文件。

```
cppCopy code#include <iostream>
#include <list>
```

### 2. 创建和初始化 `std::list`

```
cppCopy code// 创建一个空的 list
std::list<int> emptyList;

// 创建并初始化 list
std::list<int> myList = {1, 2, 3, 4, 5};
```

### 3. 访问元素

与 `std::vector` 不同，`std::list` 不支持通过下标直接访问元素。可以使用迭代器进行访问。

```
cppCopy code// 使用迭代器访问元素
std::list<int>::iterator it = myList.begin();
std::cout << "First element: " << *it << std::endl;
```

### 4. 插入和删除元素

```
cppCopy code// 在末尾插入元素
myList.push_back(6);

// 在开头插入元素
myList.push_front(0);

// 删除末尾元素
myList.pop_back();

// 删除开头元素
myList.pop_front();

// 在指定位置插入元素
std::list<int>::iterator insertPos = std::next(myList.begin(), 2);
myList.insert(insertPos, 10);

// 在指定位置删除元素
std::list<int>::iterator erasePos = std::next(myList.begin(), 1);
myList.erase(erasePos);
```

### 5. 获取容器大小和清空容器

```
cppCopy code// 获取容器大小
std::cout << "Size: " << myList.size() << std::endl;

// 清空容器
myList.clear();
```

### 6. 遍历容器

```
cppCopy code// 使用迭代器遍历
for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << " ";
}

// 使用范围-based for 循环遍历
for (int element : myList) {
    std::cout << element << " ";
}
```

### 7. 容器排序

`std::list` 不支持 `std::sort`，因为它没有提供随机访问的能力。可以使用 `std::list` 自带的 `sort` 方法。

```
cppCopy code// 对容器进行排序
myList.sort();
```

### 8. 判断容器是否为空

```
cppCopy codeif (myList.empty()) {
    std::cout << "List is empty." << std::endl;
} else {
    std::cout << "List is not empty." << std::endl;
}
```

### 9. 获取首尾元素

```
cppCopy code// 获取首元素
int firstElement = myList.front();

// 获取尾元素
int lastElement = myList.back();
```

### 10. 使用迭代器进行插入和删除

```
cppCopy code// 在指定位置插入元素
std::list<int>::iterator insertPos = std::next(myList.begin(), 2);
myList.insert(insertPos, 10);

// 在指定位置删除元素
std::list<int>::iterator erasePos = std::next(myList.begin(), 1);
myList.erase(erasePos);
```

### 11. 容器的复制

```
cppCopy code// 复制构造函数
std::list<int> copiedList(myList);

// 赋值操作符
std::list<int> assignedList = myList;
```

`std::list` 提供了一种非常灵活的动态数组实现，适用于需要频繁在中间插入和删除元素的场景。在选择使用 `std::list` 时，需要根据具体的需求来权衡各种容器的优缺点。