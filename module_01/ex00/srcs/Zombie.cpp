#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : m_name(name)
{
    std::cout << "Zombie " << m_name << " was created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << m_name << " was destroyed" << std::endl;
}

void Zombie::announce() const
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

