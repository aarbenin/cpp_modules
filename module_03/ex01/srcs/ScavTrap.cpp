#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("Default ScavTrap")
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "Default constructor called: ScavTrap " << m_name << " created\n";
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
    std::cout << "Parameterized constructor called: ScavTrap " << m_name << " created\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "Copy constructor called: ScavTrap " << m_name << " created\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "Assignment operator called: ScavTrap " << m_name << " assigned\n";
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (m_energyPoints > 0 && m_hitPoints > 0)
    {
        m_energyPoints--;
        std::cout << "ScavTrap " << m_name << " attacks " << target
                  << ", causing " << m_attackDamage << " points of damage!\n";
    }
    else
    {
        std::cout << "ScavTrap " << m_name
                  << " cannot attack (energy: " << m_energyPoints
                  << ", health: " << m_hitPoints << ")\n";
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called: ScavTrap " << m_name << " destroyed\n";
}
