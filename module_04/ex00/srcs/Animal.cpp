#include "Animal.hpp"

#include <iostream>

Animal::Animal() : m_type("Animal")
{
    std::cout << "[Animal] Default constructor called\n";
}

Animal::Animal(const Animal& other) : m_type(other.m_type)
{
    std::cout << "[Animal] Copy constructor called\n";
}

Animal::~Animal()
{
    std::cout << "[Animal] Destructor called\n";
}

Animal& Animal::operator=(const Animal& rhs)
{
    if (this != &rhs)
    {
        m_type = rhs.m_type;
    }
    std::cout << "[Animal] Assignment operator called\n";
    return *this;
}

std::string Animal::getType() const
{
    return m_type;
}

void Animal::makeSound() const
{
    std::cout << "[Animal] Some generic animal sound\n";
}
