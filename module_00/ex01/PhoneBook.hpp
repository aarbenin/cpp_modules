#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int     currentIndex;
    int     contactCount;

    std::string truncateString(const std::string &str) const;

public:
    PhoneBook();
    void add(const Contact &newContact);
    void search() const;
    void displayList() const;
    void displayDetails(int index) const;
};

#endif