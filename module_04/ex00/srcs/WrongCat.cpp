#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    m_type = "WrongCat";
    std::cout << "[WrongCat] Default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] Copy constructor called\n";
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] Destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
    }
    std::cout << "[WrongCat] Assignment operator called\n";
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat] Meow?? (But it's wrong...)\n";
}
