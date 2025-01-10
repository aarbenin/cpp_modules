#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : m_type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
    return m_type;
}

void Weapon::setType(const std::string& type)
{
    m_type = type;
}
