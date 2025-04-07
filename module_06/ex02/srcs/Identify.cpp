#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }

    int r = std::rand() % 3;
    switch (r) {
    case 0:
        std::cout << "[generate()] Creating A" << std::endl;
        return new A();
    case 1:
        std::cout << "[generate()] Creating B" << std::endl;
        return new B();
    default:
        std::cout << "[generate()] Creating C" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast& bc) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast& bc) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast& bc) {
    }

    std::cout << "Unknown type" << std::endl;
}
