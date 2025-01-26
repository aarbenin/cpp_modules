#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal()
{
    m_type = "Cat";
    std::cout << "[Cat] Default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor called\n";
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor called\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
    }
    std::cout << "[Cat] Assignment operator called\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow... meooooow...\n";
}
