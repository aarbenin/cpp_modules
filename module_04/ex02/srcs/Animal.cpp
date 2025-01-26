#include "Animal.hpp"

Animal::Animal() : m_type("Animal")
{
    std::cout << "[Animal] Default constructor called\n";
}

Animal::Animal(const Animal &other) : m_type(other.m_type)
{
    std::cout << "[Animal] Copy constructor called\n";
}

Animal::~Animal()
{
    std::cout << "[Animal] Destructor called\n";
}

Animal &Animal::operator=(const Animal &rhs)
{
    std::cout << "[Animal] Assignment operator called\n";
    if (this != &rhs)
    {
        m_type = rhs.m_type;
    }
    return *this;
}

std::string Animal::getType() const
{
    return m_type;
}
