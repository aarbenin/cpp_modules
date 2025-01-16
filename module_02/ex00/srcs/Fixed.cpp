#include "Fixed.hpp"

Fixed::Fixed() : m_value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) : m_value(other.m_value)
{
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
    {
        m_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return m_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    m_value = raw;
}
