#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "=== Simple tests ===\n\n";

    {
        std::cout << "[1] Creating a Dog and a Cat on the heap...\n\n";
        const Animal* doggo = new Dog();
        const Animal* kitty = new Cat();

        std::cout << "\n[2] Checking sounds:\n";
        doggo->makeSound();
        kitty->makeSound();

        std::cout
            << "\n[3] Deleting doggo and kitty (watch destructors)...\n\n";
        delete doggo;
        delete kitty;
    }

    std::cout << "\n=== Array of Animals ===\n\n";
    {
        const int size = 4;
        Animal*   animals[size];

        std::cout << "[1] Creating an array of " << size << " Animals...\n";
        for (int i = 0; i < size; i++)
        {
            if (i < size / 2)
            {
                animals[i] = new Dog();
            }
            else
            {
                animals[i] = new Cat();
            }
        }

        std::cout << "\n[2] Making sounds from the array...\n";
        for (int i = 0; i < size; i++)
        {
            std::cout << "  Animal #" << i << " => ";
            animals[i]->makeSound();
        }

        std::cout << "\n[3] Deleting the array (watch destructors)...\n\n";
        for (int i = 0; i < size; i++)
        {
            delete animals[i];
        }
    }

    std::cout << "\n=== Deep Copy Check ===\n\n";
    {
        Dog dog1;
        dog1.getBrain()->setIdea(0, "Eat lots of treats");
        dog1.getBrain()->setIdea(1, "Chase the cat");
        dog1.getBrain()->setIdea(2, "Bark at the mailman");
        dog1.getBrain()->setIdea(3, "Dig a hole in the backyard");
        dog1.getBrain()->setIdea(4, "Steal food from the table");

        Cat cat1;
        cat1.getBrain()->setIdea(0, "Nap in the sun");
        cat1.getBrain()->setIdea(1, "Knock over a glass of water");
        cat1.getBrain()->setIdea(2, "Ignore the human");
        cat1.getBrain()->setIdea(3, "Chase a laser pointer");
        cat1.getBrain()->setIdea(4, "Sit on the keyboard");

        std::cout << "[1] dog1 and cat1 ideas before copy:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << "  Dog Idea[" << i << "]: " << dog1.getBrain()->getIdea(i) << "\n";
            std::cout << "  Cat Idea[" << i << "]: " << cat1.getBrain()->getIdea(i) << "\n";
        }

        std::cout << "\n[2] Creating dog2 as a copy of dog1...\n";
        Dog dog2(dog1);

        std::cout << "\n[3] Changing dog2 ideas...\n";
        dog2.getBrain()->setIdea(0, "Guard the house");
        dog2.getBrain()->setIdea(1, "Nap all day");

        std::cout << "\n[4] dog1 ideas after dog2 changed its brain:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << "  Dog1 Idea[" << i << "]: " << dog1.getBrain()->getIdea(i) << "\n";
        }

        std::cout << "\n[5] dog2 ideas:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << "  Dog2 Idea[" << i << "]: " << dog2.getBrain()->getIdea(i) << "\n";
        }

        std::cout << "\n>>> If deep copy works, dog1's ideas should be unchanged!\n";
    }

    std::cout << "\n=== End of tests ===\n";
    return 0;
}
