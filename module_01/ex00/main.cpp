#include "Zombie.hpp"

int main()
{
    Zombie* emptyNameZombie = newZombie("");
    emptyNameZombie->announce();
    delete emptyNameZombie;

    std::string longName(1000, 'A');
    Zombie*     longNameZombie = newZombie(longName);
    longNameZombie->announce();
    delete longNameZombie;

    randomChump("Зомби 🧟 #1");
    randomChump("!@#$%^&*()");

    for (int i = 0; i < 5; ++i)
    {
        Zombie* cloneZombie = newZombie("Clone");
        cloneZombie->announce();
        delete cloneZombie;
    }

    // const int NUM_ZOMBIES = 50;
    // Zombie* zombieHorde[NUM_ZOMBIES];
    // for (int i = 0; i <= NUM_ZOMBIES; ++i) {
    //     zombieHorde[i] = newZombie("HordeMember_" + std::to_string(i));
    //     zombieHorde[i]->announce();
    // }
    // for (int i = 0; i <= NUM_ZOMBIES; ++i) {
    //     delete zombieHorde[i];
    // }

    return 0;
}
