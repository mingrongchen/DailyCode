# C++生产者消费者

生产者-消费者问题是一个经典的多线程同步问题，涉及到生产者将数据放入共享缓冲区，而消费者从缓冲区中取出数据。以下是一个简单的 C++ 实现：

```c++
cppCopy code#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;  // 共享缓冲区
const int bufferSize = 5;  // 缓冲区大小
std::mutex mtx;  // 互斥锁，保护共享数据访问
std::condition_variable bufferNotEmpty;  // 缓冲区非空的条件变量
std::condition_variable bufferNotFull;   // 缓冲区未满的条件变量

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);

        // 检查缓冲区是否已满，若已满则等待
        bufferNotFull.wait(lock, [] { return buffer.size() < bufferSize; });

        // 生产数据并放入缓冲区
        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;

        // 通知消费者缓冲区非空
        bufferNotEmpty.notify_all();
    }
}

void consumer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);

        // 检查缓冲区是否为空，若为空则等待
        bufferNotEmpty.wait(lock, [] { return !buffer.empty(); });

        // 消费数据并从缓冲区中取出
        int data = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << data << std::endl;

        // 通知生产者缓冲区未满
        bufferNotFull.notify_all();
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
```

上述代码中，`std::queue` 表示共享缓冲区，`std::mutex` 用于保护对缓冲区的访问，`std::condition_variable` 用于实现条件等待。生产者线程负责生产数据并将其放入缓冲区，消费者线程负责从缓冲区中取出数据并进行消费。

在生产者和消费者的主循环中，使用 `std::unique_lock` 加锁和解锁互斥锁，以确保在对缓冲区的访问是互斥的。`bufferNotFull.wait` 和 `bufferNotEmpty.wait` 分别用于生产者和消费者的条件等待，以避免缓冲区满或空时的等待。

这样的实现保证了生产者和消费者在操作共享缓冲区时的同步，确保线程安全。在实际应用中，可以根据需要进一步扩展和优化。