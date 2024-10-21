#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie(std::string zombie_name);
    ~Zombie();
    void announce() const;

private:
    std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif