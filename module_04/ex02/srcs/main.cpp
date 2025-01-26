#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "=== Testing that Animal is now abstract ===\n\n";

    // Uncommenting this line should cause a compile error:
    //  Animal testAnimal;             // Error: ‘Animal’ is an abstract class
    //  Animal* testAnimalPtr = new Animal(); // Error: ‘Animal’ is an abstract
    //  class

    std::cout << "[1] Creating Dog and Cat objects...\n\n";
    const Animal* doggo = new Dog();
    const Animal* kitty = new Cat();

    std::cout << "\n[2] Checking sounds:\n";
    doggo->makeSound();
    kitty->makeSound();

    std::cout << "\n[3] Deleting doggo and kitty (watch destructors)...\n\n";
    delete doggo;
    delete kitty;

    std::cout << "\n=== Array of Animals (actually Dogs & Cats) ===\n\n";
    {
        const int size = 4;
        Animal*   animals[size];

        for (int i = 0; i < size; i++)
        {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << "\n[1] Making sounds from the array...\n";
        for (int i = 0; i < size; i++)
        {
            std::cout << "  Animal #" << i << " => ";
            animals[i]->makeSound();
        }

        std::cout << "\n[2] Deleting the array (watch destructors)...\n\n";
        for (int i = 0; i < size; i++)
        {
            delete animals[i];
        }
    }

    std::cout << "\n=== Deep Copy Check (Cat) ===\n\n";
    {
        Cat cat1;
        cat1.getBrain()->setIdea(0, "Nap in the sun for hours");
        cat1.getBrain()->setIdea(1, "Knock over a glass of water");

        std::cout << "cat1 ideas before copy:\n";
        std::cout << "  Idea[0]: " << cat1.getBrain()->getIdea(0) << "\n";
        std::cout << "  Idea[1]: " << cat1.getBrain()->getIdea(1) << "\n";

        std::cout << "\nCreating cat2 as a copy of cat1...\n";
        Cat cat2(cat1);

        std::cout << "\nChanging cat2 ideas...\n";
        cat2.getBrain()->setIdea(0, "Steal the warmest spot on the bed");
        cat2.getBrain()->setIdea(1, "Purr loudly to manipulate the human");

        std::cout << "\nAfter changing cat2's ideas:\n";
        std::cout << "  cat1 Idea[0]: " << cat1.getBrain()->getIdea(0) << "\n";
        std::cout << "  cat1 Idea[1]: " << cat1.getBrain()->getIdea(1) << "\n";
        std::cout << "  cat2 Idea[0]: " << cat2.getBrain()->getIdea(0) << "\n";
        std::cout << "  cat2 Idea[1]: " << cat2.getBrain()->getIdea(1) << "\n";

        std::cout
            << "\n>>> If deep copy works, cat1's ideas remain unchanged!\n";
    }

    std::cout << "\n=== End of tests ===\n";
    return 0;
}
