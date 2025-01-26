#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	~Brain();
	Brain& operator=(const Brain& rhs);

	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;

private:
	std::string m_ideas[100];
};

#endif