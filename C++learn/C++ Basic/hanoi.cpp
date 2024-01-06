#include<iostream>


void move(int n, char source, char target) {
    std::cout << "(" << n << ", " << source << "--->" << target << ")" << std::endl;
}

void hanoi(int n , char A, char B, char C) {
    if (n == 1) {
        // 移动最小的那个盘子
        move(1, A, C);
    } else {
        // 将A柱上的n-1个盘子，借助C柱，移动到B柱上
        hanoi(n-1, A, C, B);
        // 将剩下的A柱上第n个盘子，移动到C柱上
        move(n, A, C);
        // 将B柱上的n-1个盘子，借助A柱，移动到C柱上
        hanoi(n-1, B, A, C);
    }
}

int main() {
    int num;
    std::cout << "Input the number of disk: ";
    std::cin >> num;

    hanoi(num, 'A', 'B', 'C');
    
    return 0;
}