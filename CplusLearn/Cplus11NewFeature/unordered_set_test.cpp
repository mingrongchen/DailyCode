#include<iostream>
#include<string>
#include<unordered_set>
#include<set>

int main() {
    // unordered_set 红黑树实现，内部值不会重复，不会自动排序
    std::unordered_set<int> unordered_set;
    unordered_set.insert(7);
    unordered_set.insert(5);
    unordered_set.insert(3);
    unordered_set.insert(4);
    unordered_set.insert(4);
    unordered_set.insert(6);


    std::cout << "unordered_set: " << std::endl;

    for (auto itor: unordered_set) {
        std::cout << itor << std::endl;
    }

    // set红黑树实现，内部值不会重复，自动排序
    std::set<int> set;
    set.insert(7);
    set.insert(5);
    set.insert(3);
    set.insert(4);
    set.insert(6);

    std::cout << "set: " << std::endl;
    for (auto itor : set) {
        std::cout << itor << std::endl;
    }

    return 0;
}