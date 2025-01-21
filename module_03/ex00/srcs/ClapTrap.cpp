#include "ClapTrap.hpp"

#include <limits>

ClapTrap::ClapTrap()
    : m_name("Default"), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "Default constructor called: ClapTrap " << m_name
              << " created\n";
}

ClapTrap::ClapTrap(const std::string& name)
    : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
    std::cout << "Parameterized constructor called: ClapTrap " << m_name
              << " created\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : m_name(other.m_name),
      m_hitPoints(other.m_hitPoints),
      m_energyPoints(other.m_energyPoints),
      m_attackDamage(other.m_attackDamage)
{
    std::cout << "Copy constructor called: ClapTrap " << m_name << " created\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called: ClapTrap " << m_name << " destroyed\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        m_name         = other.m_name;
        m_hitPoints    = other.m_hitPoints;
        m_energyPoints = other.m_energyPoints;
        m_attackDamage = other.m_attackDamage;
    }
    std::cout << "Assignment operator called: ClapTrap " << m_name
              << " assigned\n";
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (m_energyPoints > 0 && m_hitPoints > 0)
    {
        m_energyPoints--;
        std::cout << "ClapTrap " << m_name << " attacks " << target
                  << ", causing " << m_attackDamage << " points of damage!\n";
    }
    else
    {
        std::cout << "ClapTrap " << m_name
                  << " cannot attack (energy: " << m_energyPoints
                  << ", health: " << m_hitPoints << ")\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (m_hitPoints == 0)
    {
        std::cout << "ClapTrap " << m_name
                  << " is already destroyed and cannot take more damage.\n";
        return;
    }

    if (amount == 0)
    {
        std::cout << "ClapTrap " << m_name << " takes no damage.\n";
        return;
    }

    if (amount >= m_hitPoints)
    {
        std::cout << "ClapTrap " << m_name << " takes " << m_hitPoints
                  << " points of damage and is destroyed!\n";
        m_hitPoints = 0;
        return;
    }

    m_hitPoints -= amount;

    std::cout << "ClapTrap " << m_name << " takes " << amount
              << " points of damage. Remaining health: " << m_hitPoints << '\n';
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_hitPoints == 0 || m_energyPoints == 0)
    {
        std::cout << "ClapTrap " << m_name
                  << " cannot repair (energy: " << m_energyPoints
                  << ", health: " << m_hitPoints << ").\n";
        return;
    }

    if (amount == 0)
    {
        std::cout << "ClapTrap " << m_name << " repairs nothing (amount: 0).\n";
        return;
    }

    unsigned int maxHealth = std::numeric_limits<unsigned int>::max();
    unsigned int actualRepair =
        (amount > maxHealth - m_hitPoints) ? (maxHealth - m_hitPoints) : amount;

    if (actualRepair != amount)
    {
        std::cout << "ClapTrap " << m_name
                  << ": Repair amount exceeded maximum health. Adjusting to "
                  << actualRepair << ".\n";
    }

    m_energyPoints--;
    m_hitPoints += actualRepair;

    std::cout << "ClapTrap " << m_name << " repairs itself, restoring "
              << actualRepair
              << " health points. Current health: " << m_hitPoints << ".\n";
}

