#include<iostream>
#include<array>


int main() {

    std::array<int, 4> arrayDemo = {1,2,3,4};

    std::cout<< "arrayDemo: " << std::endl;

    for (auto itor: arrayDemo) {
        std::cout<< itor << std::endl;
    }
    std::cout << "arrayDemo size: " << sizeof(arrayDemo) << std::endl;

    return 0;
}