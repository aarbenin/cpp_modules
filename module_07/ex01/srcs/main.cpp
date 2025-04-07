#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(T const& elem) {
    std::cout << elem << std::endl;
}

int main() {
    {
        std::cout << "=== Test with int array ===" << std::endl;
        int         arrInt[] = {42, 1337, 2023, -1, 0};
        std::size_t length   = sizeof(arrInt) / sizeof(arrInt[0]);

        ::iter(arrInt, length, printElement<int>);
    }

    {
        std::cout << "\n=== Test with string array ===" << std::endl;
        std::string arrStr[] = {"Hello", "World", "42", "Iter"};
        std::size_t length   = sizeof(arrStr) / sizeof(arrStr[0]);

        ::iter(arrStr, length, printElement<std::string>);
    }

    return 0;
}
