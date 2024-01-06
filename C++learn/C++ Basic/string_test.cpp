#include<iostream>
#include<cstdio>
#include<cassert>
#include<string>
#include<cstring>

char* myStrcpy(char* dest, const char* src) {
    assert(dest != nullptr && src != nullptr);

    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }

    if (dest == src) {
        return dest;
    }

    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}

size_t myStrlen(const char* str) {
    // 传空指针会崩溃
    assert(str != nullptr);

    // 1、常规方式
    // int count = 0;
    // while (*str != '\0') {
    //     count++;
    //     str++;
    // }

    // 2、指针方式
    const char* start = str;    // start指向str首地址
    while (*str != '\0') {
        str++;
    }

    // return count;
    return str - start;
}

char* myStrcat(char* dest, const char* src) {
    assert(dest != nullptr && src != nullptr);

    char* tmp = dest;
    while(*dest != '\0') {
        dest++;
    }

    while (*dest++ = *src++);

    return tmp;
}

void* myMemcpy(void* dest, const void* src, size_t n) {
    char* pdest, *psrc;

    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }

    if ((dest > src) && (char*)src + n > (char*)dest) {
        std::cout << "address overlap ..." << std::endl;
        // 出现地址重叠，从后向前拷贝
        pdest = (char*)dest + n - 1;
        psrc = (char*)src + n - 1;

        while (n--) {
            *pdest-- = *psrc--;
        }
    } else {
        pdest = (char*)dest;
        psrc = (char*)src;
        while (n--) {
            *pdest++ = *psrc++;
        }
    }

    return pdest;
}

void test() {
    char begin[] = "begin";
    char sentence[] = "Hello world!";
    char dest[20];
    // 1、strcpy测试
    // strcpy(dest, sentence);
    // myStrcpy(dest, sentence);

    // std::cout << "strcpy dest is : " << dest << std::endl;

    // 2、strlen测试
    // std::cout << "strlen sizeof is : " << sizeof(sentence) << std::endl;
    // std::cout << "myStrlen sentence is : " << myStrlen(sentence) << std::endl;
    // std::cout << "strlen sentence is : " << strlen(sentence) << std::endl;

    // 3、strcat测试
    // strcat(begin, sentence);
    // myStrcat(begin, sentence);
    // std::cout << "after strcat begin is : " << begin << std::endl;

    // 4、memcpy测试
    memcpy(dest, begin, sizeof(begin)/sizeof(begin[0]));
    std::cout << "after memcpy, dest is :" << dest << std::endl;

}


int main() {

    test();

    return 0;
}