#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

	Fixed d;
	d.setRawBits(1234);
	Fixed e(d);
	std::cout << "d:	" << d.getRawBits() << std::endl;
	std::cout << "e:	" << e.getRawBits() << std::endl;

    return 0;
}
