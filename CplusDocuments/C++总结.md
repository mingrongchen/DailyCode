#### 1、C++函数中形参*&的作用

在C++中，传递指针或引用的目的是允许函数修改调用者传递的实际参数。用 `*&` 表示传递一个指向指针的引用。这样可以在函数内部修改指针所指向的地址，从而影响调用者。

```c++
#include <iostream>

void modifyPointer(int* &ptr) {
    // 修改指针所指的地址
    int* newPtr = new int(42);
    delete ptr; // 释放原来的内存
    ptr = newPtr;
}

int main() {
    int value = 10;
    int* ptr = &value;

    std::cout << "Before: " << *ptr << std::endl;

    modifyPointer(ptr);

    std::cout << "After: " << *ptr << std::endl;

    // 注意：在实际应用中，需要在适当的时候释放内存
    delete ptr;

    return 0;
}

```

在这个例子中，`modifyPointer` 函数接受一个指向指针的引用 `int*& ptr`，并在函数内部创建了一个新的 `int` 对象，并修改了传递的指针，使其指向新创建的对象。在 `main` 函数中，我们看到指针 `ptr` 的值在调用 `modifyPointer` 后发生了变化。

这种技术对于**需要在函数内部分配或释放内存、改变指针指向的情况很有用**。然而，在实际使用中，需要小心处理内存管理，以防止内存泄漏或悬挂指针。

#### 2、C++中 文件操作

在C++中，文件操作通常涉及到使用 `<fstream>` 头文件提供的文件流类，其中包括 `ifstream`（用于读取文件）、`ofstream`（用于写入文件）和 `fstream`（用于读写文件）。下面是一些基本的文件操作的详解：

##### 2、1打开文件

要在C++中进行文件操作，首先需要打开文件。可以使用 `ofstream` 或 `ifstream` 来打开文件进行写入或读取。示例：

```c++
#include <fstream>
#include <iostream>

int main() {
    // 打开一个文件用于写入
    std::ofstream outFile("example.txt");

    if (outFile.is_open()) {
        // 写入数据到文件
        outFile << "Hello, World!\n";
        outFile << 42 << "\n";

        // 关闭文件
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

    // 打开一个文件用于读取
    std::ifstream inFile("example.txt");

    if (inFile.is_open()) {
        // 从文件读取数据
        std::string line;
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }

        // 关闭文件
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    return 0;
}

```

##### 2、2文件写入

使用 `ofstream` 来写入文件：

```c++
#include <fstream>
#include <iostream>

int main() {
    std::ofstream outFile("example.txt");

    if (outFile.is_open()) {
        outFile << "Hello, World!\n";
        outFile << 42 << "\n";
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

    return 0;
}

```

### 文件读取

使用 `ifstream` 来读取文件：

```c++
#include <fstream>
#include <iostream>

int main() {
    std::ifstream inFile("example.txt");

    if (inFile.is_open()) {
        std::string line;
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    return 0;
}

```

### 文件追加

如果想要在文件末尾追加内容，可以使用 `std::ios::app` 标志：

```c++
#include <fstream>
#include <iostream>

int main() {
    std::ofstream outFile("example.txt", std::ios::app);

    if (outFile.is_open()) {
        outFile << "Appending new line!\n";
        outFile.close();
    } else {
        std::cerr << "Unable to open file for appending." << std::endl;
    }

    return 0;
}

```







