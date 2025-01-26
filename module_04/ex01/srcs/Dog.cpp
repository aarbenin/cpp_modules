#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
    m_type  = "Dog";
    m_brain = new Brain();
    std::cout << "[Dog] Default constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] Copy constructor called\n";
    m_brain = new Brain(*(other.m_brain));
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called\n";
    delete m_brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "[Dog] Assignment operator called\n";
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete m_brain;
        m_brain = new Brain(*(rhs.m_brain));
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof! Woof!\n";
}

Brain* Dog::getBrain() const
{
    return m_brain;
}