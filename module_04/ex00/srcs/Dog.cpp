#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
    m_type = "Dog";
    std::cout << "[Dog] Default constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] Copy constructor called\n";
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called\n";
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
    }
    std::cout << "[Dog] Assignment operator called\n";
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof! Woof!\n";
}
