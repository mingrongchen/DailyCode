#include<iostream>

int fac(int n) {
    int t;
    if (n == 1) {
        t = 1;
    } else {
        t = n * fac(n - 1);
    }

    return t;
}

int main() {
    const int max_n = 12;
    int n;
    std::cout << "Input a integer number: ";
    std::cin >> n;
    if (n >= 1 && n <= max_n) {
        std::cout << "Factorial of " << n << " is : " << fac(n) << std::endl;
    } else {
        std::cout << "Invalid n." << std::endl;
    }

    return 0;
}