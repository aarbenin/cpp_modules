#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();

    Animal      &operator=(const Animal &rhs);
    virtual void makeSound() const = 0;

    std::string getType() const;

protected:
    std::string m_type;
};

#endif
