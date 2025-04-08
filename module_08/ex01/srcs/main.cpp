#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    {
        unsigned int n = 10000;
        Span         bigSpan(n);
        srand(time(NULL));
        for (unsigned int i = 0; i < n; i++) {
            bigSpan.addNumber(rand());
        }
        std::cout << "Big span of 10000 numbers:" << std::endl;
        try {
            std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
            std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "--------------------------" << std::endl;

    {
        Span             spRange(10);
        std::vector<int> v;
        for (int i = 0; i < 5; i++) {
            v.push_back(i * 10);
        }

        try {
            spRange.addRange(v.begin(), v.end());
            std::cout << "Shortest span: " << spRange.shortestSpan()
                      << std::endl;
            std::cout << "Longest span: " << spRange.longestSpan() << std::endl;

            int arr[] = {42, 43, 44, 45, 46};
            spRange.addRange(arr, arr + 5);

            spRange.addNumber(999);
        } catch (const std::exception& e) {
            std::cerr << "Exception in spRange: " << e.what() << std::endl;
        }
    }

    return 0;
}
