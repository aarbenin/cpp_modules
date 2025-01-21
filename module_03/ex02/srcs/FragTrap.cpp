#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap("Default FragTrap")
{
    m_hitPoints    = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "Default constructor called: FragTrap created\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    m_hitPoints    = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
    std::cout << "Parameterized constructor called: FragTrap " << m_name
              << " created\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "Copy constructor called: FragTrap " << m_name << " created\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "Assignment operator called: FragTrap " << m_name
              << " assigned\n";
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << m_name << " requests a high five! 🙌\n";
}

void FragTrap::attack(const std::string& target)
{
    if (m_energyPoints > 0 && m_hitPoints > 0)
    {
        m_energyPoints--;
        std::cout << "FragTrap " << m_name << " attacks " << target
                  << ", causing " << m_attackDamage << " points of damage!\n";
    }
    else
    {
        std::cout << "FragTrap " << m_name
                  << " cannot attack (energy: " << m_energyPoints
                  << ", health: " << m_hitPoints << ")\n";
    }
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called: FragTrap " << m_name << " destroyed\n";
}
