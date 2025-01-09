#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name) : m_name(name) {
    std::cout << "Zombie " << m_name << " was created\n";
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << m_name << " was destroyed\n";
}

void Zombie::announce()
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}