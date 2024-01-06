#include<iostream>



int main() {
    int numbers[] = {1,2,3,4,5};
    std::cout << "numbers: " << std::endl;

    for (auto number : numbers)
    {
        std::cout << number <<std::endl;
    }
    


    return 0;
}