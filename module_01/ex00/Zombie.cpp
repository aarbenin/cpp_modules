#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string zombie_name) : name(zombie_name)
{
    std::cout << "Zombie " << name << " was created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " was destroyed" << std::endl;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

