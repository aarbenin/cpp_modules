#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <vector>

class Span {
public:
    class StorageLimitReached : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span storage limit reached";
        }
    };

    class NotEnoughElements : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Not enough elements in Span";
        }
    };

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        unsigned int distance = std::distance(begin, end);
        if (_numbers.size() + distance > _capacity) {
            throw StorageLimitReached();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;

    int longestSpan() const;

private:
    std::vector<int> _numbers;
    unsigned int     _capacity;
};

#endif
