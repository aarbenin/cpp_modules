#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Test 1: default constructor (empty array) ===\n";
    Array<int> empty;
    std::cout << "Size of empty array: " << empty.size() << std::endl;
    try {
        std::cout << "Trying empty[0]...\n";
        empty[0] = 42;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: array of int ===\n";
    unsigned int n = 5;
    Array<int>   intArray(n);
    std::cout << "Size of intArray: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    std::cout << "Contents of intArray:\n";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    std::cout << "\n=== Test 3: copy constructor ===\n";
    {
        Array<int> copyArray(intArray);
        std::cout << "Size of copyArray: " << copyArray.size() << std::endl;
        copyArray[0] = 999;
        std::cout << "copyArray[0] = " << copyArray[0] << std::endl;
        std::cout << "intArray[0] = " << intArray[0]
                  << " (should be unchanged)\n";
    }

    std::cout << "\n=== Test 4: assignment operator ===\n";
    {
        Array<int> assigned = intArray;
        std::cout << "assigned.size() = " << assigned.size() << std::endl;
        assigned[1] = 1234;
        std::cout << "assigned[1] = " << assigned[1] << std::endl;
        std::cout << "intArray[1] = " << intArray[1]
                  << " (should be unchanged)\n";
    }

    std::cout << "\n=== Test 5: array of std::string ===\n";
    {
        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "Array";
        strArray[2] = "World";
        for (unsigned int i = 0; i < strArray.size(); i++) {
            std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
        }
    }

    std::cout << "\n=== Test 6: out of range ===\n";
    try {
        std::cout << "intArray[9999] = " << intArray[9999] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
