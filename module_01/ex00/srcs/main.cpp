#include "Zombie.hpp"
#include <iostream>


int main()
{
    std::cout << "\nCreating heap zombie:\n";
    Zombie* rob = newZombie("Rotty Rob");
    if (rob != nullptr)
    {
        rob->announce();
        delete rob;
    }

    std::cout << "\nCreating stack zombie with function:\n";
    randomChump("Biter Bob");

    std::cout << "\nCreating stack zombie with constructor:\n";
    Zombie zombella("Zombella");
    zombella.announce();

    return 0;
}