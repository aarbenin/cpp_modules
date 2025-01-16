#include "Fixed.hpp"

// ============================== Constructors ==============================

Fixed::Fixed() : m_value(0)
{
    //std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intValue)
{
    //std::cout << "Int constructor called\n";
    m_value = intValue << m_fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    //std::cout << "Float constructor called\n";
    m_value = std::roundf(floatValue * (1 << m_fractionalBits));
}

Fixed::Fixed(const Fixed& other) : m_value(other.m_value)
{
    //std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called\n";
    if (this != &other)
    {
        m_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called\n";
}

// ============================== Getters and setters ==============================

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called\n";
    return m_value;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called\n";
    m_value = raw;
}

// ============================== Conversion methods ==============================

float Fixed::toFloat() const
{
    return static_cast<float>(m_value) / (1 << m_fractionalBits);
}

int Fixed::toInt() const
{
    return m_value >> m_fractionalBits;
}

// ============================== Output operators ==============================

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

// ============================== Comparison operators ==============================

bool Fixed::operator>(const Fixed& other) const
{
    return this->m_value > other.m_value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->m_value < other.m_value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->m_value >= other.m_value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->m_value <= other.m_value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->m_value == other.m_value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->m_value != other.m_value;
}

// ============================== Arithmetic operators ==============================

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

// ============================== Increment and decrement ==============================

Fixed& Fixed::operator++()  // prefix
{
    ++this->m_value;
    return *this;
}

Fixed Fixed::operator++(int)  // postfix
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--()  // prefix
{
    --this->m_value;
    return *this;
}

Fixed Fixed::operator--(int)  // postfix
{
    Fixed temp(*this);
    --(*this);
    return temp;
}

// ============================== Min and max ==============================

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}
