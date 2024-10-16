#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0)
{
}

void PhoneBook::add(const Contact& newContact)
{
    contacts[currentIndex] = newContact;
    currentIndex           = (currentIndex + 1) % 8;
    if (contactCount < 8)
    {
        contactCount++;
    }
}

std::string PhoneBook::truncateString(const std::string& str) const
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::displayList() const
{
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10)
              << "First Name" << "|" << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; ++i)
    {
        std::cout << std::setw(10) << (i + 1) << "|" << std::setw(10)
                  << truncateString(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName())
                  << "|" << std::setw(10)
                  << truncateString(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayDetails(int index) const
{
    if (index < 0 || index >= contactCount)
    {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
        return;
    }
    const Contact& contact = contacts[index];
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "          Contact Details               " << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << std::setw(20) << "First Name: " << contact.getFirstName()
              << std::endl;
    std::cout << std::setw(20) << "Last Name: " << contact.getLastName()
              << std::endl;
    std::cout << std::setw(20) << "Nickname: " << contact.getNickname()
              << std::endl;
    std::cout << std::setw(20) << "Phone Number: " << contact.getPhoneNumber()
              << std::endl;
    std::cout << std::setw(20)
              << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
}

void PhoneBook::search() const
{
    if (contactCount == 0)
    {
        std::cout << "The phonebook is empty. Please add at least one contact."
                  << std::endl;
        return;
    }

    displayList();
    int index;
    std::cout << "Enter the index of the contact to view details (from 1 to "
              << contactCount << "): ";
    std::cin >> index;

    if (std::cin.fail() || index < 1 || index > contactCount)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index. Please try again." << std::endl;
        return;
    }

    displayDetails(index - 1);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
