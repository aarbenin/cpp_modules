#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential pardon form", SIGN_GRADE, EXEC_GRADE, "default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential pardon form", SIGN_GRADE, EXEC_GRADE, target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other) {}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);

    std::cout << getTarget()
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}