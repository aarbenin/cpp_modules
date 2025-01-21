#include <limits>
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n=== ScavTrap initialization ===\n";
    ScavTrap scav("Guardian");

    std::cout << "\n=== Testing attack ===\n";
    scav.attack("Target1");

    std::cout << "\n=== Testing take damage ===\n";
    scav.takeDamage(30);
    scav.takeDamage(80);
    scav.takeDamage(1);

    std::cout << "\n=== Testing repair ===\n";
    scav.beRepaired(50);

    std::cout << "\n=== Testing special ability ===\n";
    scav.guardGate();

    std::cout << "\n=== Restoring state ===\n";
    ScavTrap restoredScav("Guardian 2.0");
    restoredScav.takeDamage(20);
    restoredScav.beRepaired(30);

    std::cout << "\n=== Energy depletion ===\n";
    for (int i = 0; i < 51; ++i)
    {
        restoredScav.attack("Target2");
    }

    std::cout << "\n=== Attempting actions without energy ===\n";
    restoredScav.attack("Target3");
    restoredScav.beRepaired(10);

    std::cout << "\n=== Edge case: massive repair ===\n";
    restoredScav = ScavTrap("Overflowy");
    restoredScav.beRepaired(std::numeric_limits<unsigned int>::max());

    std::cout << "\n=== Edge case: massive damage ===\n";
    restoredScav.takeDamage(std::numeric_limits<unsigned int>::max());

    std::cout << "\n=== End of tests ===\n";
    return 0;
}
