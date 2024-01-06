#include<iostream>



// 指针数组，表示指向指针的数组，用法：常用于存储若干行字符串
void test1() {
    char* sentences[] = {
        "I'm a Chinese.",
        "I come from Beijing.",
        "I like computer science.",
        "Programming is funny!"
    };

    for (auto sentence : sentences) {
        std::cout << sentence << std::endl;
    }
}


// 数组指针，表示指向数组的指针，用法：多用于处理二维数组
void test2() {


}

int main() {
    test1();


    return 0;
}