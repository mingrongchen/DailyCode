#include<iostream>

int max(int x, int y) {
    int z;
    z = (x > y) ? x : y;
    return z;
}

int main() {
    int a, b ;
    std::cin >> a >> b;
    std::cout << max(a, b) << std::endl;

    return 0;
}