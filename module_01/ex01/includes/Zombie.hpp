#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
public:
    Zombie();
    ~Zombie();

    void announce();
    void setName(const std::string& name);

private:
    std::string m_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif