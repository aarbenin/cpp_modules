#ifndef CAT_HPP
#define CAT_HPP

#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat& other);
    ~Cat();
    Cat& operator=(const Cat& rhs);

    void   makeSound() const override;
    Brain* getBrain() const;

private:
    Brain* m_brain;
};

#endif
