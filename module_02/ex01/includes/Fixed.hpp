#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);

    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    ~Fixed();

    int   getRawBits() const;
    void  setRawBits(int const raw);
    float toFloat() const;
    int   toInt() const;

private:
    int              m_value;
    static const int m_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
