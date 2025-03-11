#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

const char* Intern::FormNotFoundException::what() const noexcept {
    return "form type not found";
}

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) const {
    struct FormType {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    const FormType formTypes[] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}};

    const int formCount = sizeof(formTypes) / sizeof(formTypes[0]);

    for (int i = 0; i < formCount; i++) {
        if (formName == formTypes[i].name) {
            AForm* form = formTypes[i].create(target);
            std::cout << "🔄 Intern creates \"" << form->getName() << "\""
                      << std::endl;
            return form;
        }
    }

    std::cout << "❌ Intern couldn't create form: unknown form type \""
              << formName << "\"" << std::endl;
    throw FormNotFoundException();
}