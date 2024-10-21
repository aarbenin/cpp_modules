#include <iostream>
#include <string>
#include <cctype>

#include "Contact.hpp"
#include "PhoneBook.hpp"

bool isNumber(const std::string &str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main()
{
    PhoneBook   phoneBook;
    std::string command;

    std::cout << "Welcome to my awesome phonebook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

    while (true)
    {
        std::cout << "Enter your command: ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber,
                darkestSecret;

            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            while (true) {
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phoneNumber);
                
                if (isNumber(phoneNumber)) {
                    break;
                } else {
                    std::cout << "Error: Phone number must contain only digits. Please try again." << std::endl;
                }
            }
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);
             if (darkestSecret.empty()) {
                std::cout << "Not confessing, are we? Well, I'll have to do it for you..." << std::endl;
                darkestSecret = "Secretly likes pineapple on pizza 😱";
            }

            if (firstName.empty() || lastName.empty() || nickname.empty() ||
                phoneNumber.empty() || darkestSecret.empty())
            {
                std::cout
                    << "Error: All fields must be filled. Contact not added."
                    << std::endl;
            }
            else
            {
                Contact newContact(firstName, lastName, nickname, phoneNumber,
                                   darkestSecret);
                phoneBook.add(newContact);
                std::cout << "\nContact added successfully!\n" << std::endl;
            }
        }
        else if (command == "SEARCH")
        {
            phoneBook.search();
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT."
                      << std::endl;
        }
    }
    return 0;
}
