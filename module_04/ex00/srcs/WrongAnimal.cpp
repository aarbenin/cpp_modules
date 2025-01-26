#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : m_type("WrongAnimal")
{
    std::cout << "[WrongAnimal] Default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : m_type(other.m_type)
{
    std::cout << "[WrongAnimal] Copy constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] Destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    if (this != &rhs)
    {
        m_type = rhs.m_type;
    }
    std::cout << "[WrongAnimal] Assignment operator called\n";
    return *this;
}

std::string WrongAnimal::getType() const
{
    return m_type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] Some weird wrong sound\n";
}
