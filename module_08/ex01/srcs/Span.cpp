#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n) : _numbers(), _capacity(n) {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_capacity = other._capacity;
        this->_numbers  = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _capacity) {
        throw StorageLimitReached();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughElements();
    }

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = std::numeric_limits<int>::max();

    for (std::vector<int>::size_type i = 0; i < tmp.size() - 1; i++) {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughElements();
    }
    std::vector<int>::const_iterator minIt =
        std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt =
        std::max_element(_numbers.begin(), _numbers.end());

    return *maxIt - *minIt;
}
