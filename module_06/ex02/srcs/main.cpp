#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identify.hpp"
#include <iostream>

int main() {
    std::cout << "=== Automatic random tests ===" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        std::cout << "identify(*ptr): ";
        identify(*ptr);
        std::cout << "identify(ptr):  ";
        identify(ptr);
        delete ptr;
        std::cout << "----------------\n";
    }

    std::cout << "\n=== Manual tests ===" << std::endl;
    A     a;
    B     b;
    C     c;
    Base* ptrA = &a;
    Base* ptrB = &b;
    Base* ptrC = &c;

    std::cout << "identify(ptrA): ";
    identify(ptrA);
    std::cout << "identify(*ptrA): ";
    identify(*ptrA);

    std::cout << "identify(ptrB): ";
    identify(ptrB);
    std::cout << "identify(*ptrB): ";
    identify(*ptrB);

    std::cout << "identify(ptrC): ";
    identify(ptrC);
    std::cout << "identify(*ptrC): ";
    identify(*ptrC);

    return 0;
}
