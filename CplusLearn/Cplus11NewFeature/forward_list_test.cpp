#include<iostream>
#include<forward_list>


int main() {


    std::forward_list<int> numbers = {1,2,3,4,5,6};

    std::cout << "numbers: " << std::endl;


    for (auto number:numbers) {
        std::cout << number << std::endl;
    }

    numbers.remove(4);
    std::cout << "forward list size : " << std::distance(numbers.begin(), numbers.end()) << std::endl;
    std::cout << "numbers after remove: " << std::endl;
    for (auto number:numbers) {
        std::cout << number << std::endl;
    }

    return 0;
}