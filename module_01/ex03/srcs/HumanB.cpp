#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : m_name(name) {}

HumanB::~HumanB() {}

void HumanB::attack() const
{
    if (m_weapon)
    {
        std::cout << m_name << " attacks with their " << m_weapon->getType() << "\n";
    } else 
    {
        std::cout << m_name << " has no weapon to attack with\n";
    }
}

void HumanB::setWeapon(Weapon& weapon)
{
    m_weapon = &weapon;
}