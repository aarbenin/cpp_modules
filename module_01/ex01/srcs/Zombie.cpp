#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie()
{
    std::cout << "Zombie was created\n";
}

void Zombie::setName(const std::string& name)
{
    m_name = name;
}

void Zombie::announce()
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}
Zombie::~Zombie()
{
    std::cout << "Zombie " << m_name << " was destroyed\n";
}