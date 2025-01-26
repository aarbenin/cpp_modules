// Brain.cpp
#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
    std::cout << "[Brain] Default constructor called\n";
    for (int i = 0; i < 100; i++)
    {
        m_ideas[i] = "Thinking...";
    }
}

Brain::Brain(const Brain& other)
{
    std::cout << "[Brain] Copy constructor called\n";
    for (int i = 0; i < 100; i++)
    {
        m_ideas[i] = other.m_ideas[i];
    }
}

Brain::~Brain()
{
    std::cout << "[Brain] Destructor called\n";
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "[Brain] Assignment operator called\n";
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
        {
            m_ideas[i] = rhs.m_ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
    {
        m_ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return m_ideas[index];
    }
    return "";
}
