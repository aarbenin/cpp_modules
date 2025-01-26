#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& other);
    ~Dog();
    Dog& operator=(const Dog& rhs);

    void   makeSound() const override;
    Brain* getBrain() const;

private:
    Brain* m_brain;
};

#endif
