#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(const std::string& level)
{
    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning,
                                   &Harl::error};

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; ++i)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cerr << "Invalid level: " << level << std::endl;
}

void Harl::debug()
{
    std::cout << "DEBUG: I love having extra bacon for my burger!" << std::endl;
}

void Harl::info()
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money!"
              << std::endl;
}

void Harl::warning()
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free!"
              << std::endl;
}

void Harl::error()
{
    std::cout
        << "ERROR: This is unacceptable! I want to speak to the manager now."
        << std::endl;
}
