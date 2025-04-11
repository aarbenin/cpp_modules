#include "PmergeMe.hpp"
#include <chrono>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

static bool parsePositiveInt(const std::string& s, int& out) {
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); i++) {
        if (!std::isdigit(s[i]))
            return false;
    }
    long long val = std::atoll(s.c_str());
    if (val <= 0 || val > INT_MAX) {
        return false;
    }
    out = static_cast<int>(val);
    return true;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error\n";
        return 1;
    }

    std::vector<int> vec;
    vec.reserve(argc - 1);
    std::deque<int> deq;

    for (int i = 1; i < argc; i++) {
        int value;
        if (!parsePositiveInt(argv[i], value)) {
            std::cerr << "Error\n";
            return 1;
        }
        vec.push_back(value);
        deq.push_back(value);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i + 1 < vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    auto startVec = std::chrono::high_resolution_clock::now();
    PmergeMe::fordJohnsonSortVector(vec);
    auto endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durVec = endVec - startVec;

    auto startDeq = std::chrono::high_resolution_clock::now();
    PmergeMe::fordJohnsonSortDeque(deq);
    auto endDeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durDeq = endDeq - startDeq;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i + 1 < vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << durVec.count() << " us\n";
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : " << durDeq.count() << " us\n";

    return 0;
}
