# C++ 多线程详解

在 C++ 中，多线程编程是一种利用操作系统提供的多线程支持来实现并行执行的编程模式。C++11 引入了对多线程的原生支持，包括了 `<thread>` 头文件和 `std::thread` 类。以下是关于 C++ 多线程的基本概念和用法：

### 1. 创建线程

使用 `std::thread` 类创建新线程。以下是一个简单的示例：

```c++
cppCopy code#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    // 创建新线程并运行 threadFunction 函数
    std::thread myThread(threadFunction);

    // 主线程继续执行其他任务

    // 等待子线程执行完成
    myThread.join();

    return 0;
}
```

### 2. 传递参数给线程函数

可以通过在创建线程时传递参数来向线程函数传递参数。需要注意的是，传递的参数必须是可复制或可移动的。

```c++
cppCopy code#include <iostream>
#include <thread>

void threadFunction(int x, const std::string& str) {
    std::cout << "Received parameters: " << x << ", " << str << std::endl;
}

int main() {
    int value = 42;
    std::string message = "Hello, C++";

    // 创建新线程并运行 threadFunction 函数，传递参数
    std::thread myThread(threadFunction, value, message);

    // 主线程继续执行其他任务

    // 等待子线程执行完成
    myThread.join();

    return 0;
}
```

### 3. 使用 Lambda 表达式

可以使用 Lambda 表达式来定义线程函数，使得线程的逻辑更加内联化。

```c++
cppCopy code#include <iostream>
#include <thread>

int main() {
    int x = 10;
    std::string str = "Lambda Thread";

    // 创建新线程并运行 Lambda 表达式
    std::thread myThread([x, str]() {
        std::cout << "Received parameters: " << x << ", " << str << std::endl;
    });

    // 主线程继续执行其他任务

    // 等待子线程执行完成
    myThread.join();

    return 0;
}
```

### 4. 线程安全

在多线程环境中，对共享数据的访问需要进行同步，以防止竞态条件（Race Condition）等问题。可以使用 `std::mutex` 来实现互斥锁。

```c++
cppCopy code#include <iostream>
#include <thread>
#include <mutex>

std::mutex myMutex;

void threadFunction(int& counter) {
    for (int i = 0; i < 1000000; ++i) {
        std::lock_guard<std::mutex> lock(myMutex);  // 自动加锁和解锁
        counter++;
    }
}

int main() {
    int sharedCounter = 0;

    // 创建两个线程并运行 threadFunction 函数，共享 counter
    std::thread thread1(threadFunction, std::ref(sharedCounter));
    std::thread thread2(threadFunction, std::ref(sharedCounter));

    // 等待两个线程执行完成
    thread1.join();
    thread2.join();

    std::cout << "Final counter value: " << sharedCounter << std::endl;

    return 0;
}
```

### 5. 使用 `std::async` 实现异步任务

`std::async` 函数可以用于创建异步任务，并返回一个 `std::future` 对象，可以通过该对象获取异步任务的结果。

```c++
cppCopy code#include <iostream>
#include <future>

int asyncFunction() {
    std::cout << "Async function is running." << std::endl;
    return 42;
}

int main() {
    // 启动异步任务
    std::future<int> resultFuture = std::async(asyncFunction);

    // 主线程继续执行其他任务

    // 等待异步任务完成，并获取结果
    int result = resultFuture.get();
    std::cout << "Async function result: " << result << std::endl;

    return 0;
}
```

### 6. 其他多线程工具

C++ 提供了其他一些多线程工具，如 `std::condition_variable`（条件变量）、`std::atomic`（原子操作）、`std::future`（异步任务的结果）、`std::packaged_task`（包装任务）等，这些工具可以在不同的场景中提供更多的线程控制和同步机制。

总体而言，C++ 的多线程编程提供了丰富的工具和标准库支持，可以方便地实现并行计算和异步任务。在使用多线程时，需要特别注意线程安全性，避免潜在的竞态条件和死锁问题。