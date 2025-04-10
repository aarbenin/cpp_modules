#include "RPN.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error\n";
        return 1;
    }
    std::string input = argv[1];
    RPN         rpn(input);
    std::string cleanExpr;
    if (!rpn.validateInput(cleanExpr)) {
        std::cerr << "Error\n";
        return 1;
    }
    try {
        long long result = rpn.calculate(cleanExpr);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error\n";
        return 1;
    }
    return 0;
}
