#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

void printSeparator(char c = '-', int length = 70) {
    std::cout << std::string(length, c) << std::endl;
}

void printTestHeader(const std::string& testName) {
    std::cout << "\n";
    printSeparator('=');
    std::cout << "TEST: " << testName << std::endl;
    printSeparator('=');
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    printTestHeader("Converting: " + input);
    ScalarConverter::convert(input);

    return 0;
}
