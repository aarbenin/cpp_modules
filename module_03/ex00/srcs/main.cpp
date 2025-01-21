#include <limits>
#include "ClapTrap.hpp"

int main()
{
    std::cout << "\n=== ClapTrap initialization ===\n";
    ClapTrap bot("Clappy");

    std::cout << "\n=== Testing attack ===\n";
    bot.attack("Target1");

    std::cout << "\n=== Testing take damage ===\n";
    bot.takeDamage(5);
    bot.takeDamage(10);
    bot.takeDamage(1);

    std::cout << "\n=== Testing repair ===\n";
    bot.beRepaired(10);

    std::cout << "\n=== Restoring state ===\n";
    ClapTrap revivedBot("Clappy 2.0");
    revivedBot.takeDamage(7);
    revivedBot.beRepaired(5);

    std::cout << "\n=== Energy depletion ===\n";
    for (int i = 0; i < 11; ++i)
    {
        revivedBot.attack("Target2");
    }

    std::cout << "\n=== Attempting actions without energy ===\n";
    revivedBot.attack("Target3");
    revivedBot.beRepaired(5);

    std::cout << "\n=== Edge case: massive repair ===\n";
    revivedBot = ClapTrap("Overflowy");
    revivedBot.beRepaired(std::numeric_limits<unsigned int>::max());

    std::cout << "\n=== Edge case: massive damage ===\n";
    revivedBot.takeDamage(std::numeric_limits<unsigned int>::max());

    std::cout << "\n=== End of tests ===\n";
    return 0;
}
