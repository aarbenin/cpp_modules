#include <iostream>
#include <limits>
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=== FragTrap Initialization ===\n";
    FragTrap frag("Fraggy");

    std::cout << "\n=== Testing attack ===\n";
    frag.attack("Target1");

    std::cout << "\n=== Testing take damage ===\n";
    frag.takeDamage(30);
    frag.takeDamage(80);
    frag.takeDamage(10); // Should show already destroyed message

    std::cout << "\n=== Testing repair ===\n";
    frag.beRepaired(50); // Should not repair, as health is 0

    std::cout << "\n=== Testing special ability ===\n";
    frag.highFivesGuys();

    std::cout << "\n=== Restoring state ===\n";
    FragTrap revivedFrag("Fraggy 2.0");
    revivedFrag.takeDamage(50);
    revivedFrag.beRepaired(40);
    revivedFrag.attack("Target2");

    std::cout << "\n=== Energy depletion ===\n";
    for (int i = 0; i < 101; ++i)
    {
        revivedFrag.attack("Target3");
    }

    std::cout << "\n=== Attempting actions without energy ===\n";
    revivedFrag.attack("Target4");
    revivedFrag.beRepaired(10);

    std::cout << "\n=== Edge case: massive repair ===\n";
    revivedFrag = FragTrap("Overflowy");
    revivedFrag.beRepaired(std::numeric_limits<unsigned int>::max());

    std::cout << "\n=== Edge case: massive damage ===\n";
    revivedFrag.takeDamage(std::numeric_limits<unsigned int>::max());

    std::cout << "\n=== End of Tests ===\n";

    return 0;
}
