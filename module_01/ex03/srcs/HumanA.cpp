#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon& weapon) : m_name(name), m_weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const
{
    std::cout << m_name << " attacks with their " << m_weapon.getType() << "\n";
}