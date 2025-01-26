#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal()
{
    m_type  = "Cat";
    m_brain = new Brain();
    std::cout << "[Cat] Default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor called\n";
    m_brain = new Brain(*(other.m_brain));
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor called\n";
    delete m_brain;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "[Cat] Assignment operator called\n";
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete m_brain;
        m_brain = new Brain(*(rhs.m_brain));
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow... meooooow...\n";
}

Brain* Cat::getBrain() const
{
    return m_brain;
}
