#include <iostream>
#include "Zombie.hpp"

int main()
{
    int N = 1;
    Zombie* horde = zombieHorde(N, "Fluffy");
    if (horde != nullptr)
    {  
        for (int i = 0; i < N; ++i)
        {
            horde[i].announce();
        }
        delete[] horde;
    }
    else
    {
        std::cout << "Failed to create horde\n";
    }
    return 0;
}