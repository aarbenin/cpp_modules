#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing correct animal hierarchy ===\n\n";

    const Animal* beast = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nTypes:\n";
    std::cout << "  beast: " << beast->getType() << "\n";
    std::cout << "  dog:   " << dog->getType() << "\n";
    std::cout << "  cat:   " << cat->getType() << "\n";

    std::cout << "\nSounds:\n";
    std::cout << "  beast: ";
    beast->makeSound();
    std::cout << "  dog:   ";
    dog->makeSound();
    std::cout << "  cat:   ";
    cat->makeSound();

    delete beast;
    delete dog;
    delete cat;

    std::cout << "\n=== Testing wrong animal hierarchy ===\n\n";

    const WrongAnimal* wrongBeast = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\nTypes:\n";
    std::cout << "  wrongBeast: " << wrongBeast->getType() << "\n";
    std::cout << "  wrongCat:   " << wrongCat->getType() << "\n";

    std::cout << "\nSounds:\n";
    std::cout << "  wrongBeast: ";
    wrongBeast->makeSound();
    std::cout << "  wrongCat:   ";
    wrongCat->makeSound();

    delete wrongBeast;
    delete wrongCat;

    std::cout << "\n=== Direct testing of WrongCat ===\n\n";

    WrongCat myWrongCat;

    std::cout << "Type:\n";
    std::cout << "  myWrongCat: " << myWrongCat.getType() << "\n";

    std::cout << "\nSound:\n";
    std::cout << "  myWrongCat: ";
    myWrongCat.makeSound();

    return 0;
}
