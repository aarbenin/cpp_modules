#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class Array {
private:
    unsigned int _size;
    T*           _array;

public:
    Array() : _size(0), _array(nullptr) {}

    Array(unsigned int n) : _size(n) {
        _array = new T[n]();
    }

    Array(const Array& other) : _size(0), _array(nullptr) {
        *this = other;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _array;
            _size = other._size;

            if (_size > 0) {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _array[i] = other._array[i];
                }
            } else {
                _array = nullptr;
            }
        }
        return *this;
    }

    ~Array() {
        delete[] _array;
    }

    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of range");
        }
        return _array[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Array index out of range");
        }
        return _array[index];
    }

    unsigned int size() const {
        return _size;
    }
};

#endif
