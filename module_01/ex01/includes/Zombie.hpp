#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie();
    Zombie(std::string zombie_name);
    ~Zombie();

    void    announce() const;
    void    setName(const std::string& name);

private:
    std::string m_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif