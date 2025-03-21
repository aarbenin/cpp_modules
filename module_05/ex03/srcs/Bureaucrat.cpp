#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "grade is too high (must be at least 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "grade is too low (must not exceed 150)";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade "
       << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm& form) {
    if (form.isSigned()) {
        std::cout << _name << " couldn't sign \"" << form.getName()
                  << "\":\n    Form is already signed" << std::endl;
        return;
    }

    try {
        form.beSigned(*this);
        std::cout << _name << " successfully signed \"" << form.getName()
                  << "\"" << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't sign \"" << form.getName()
                  << "\":\n    Reason: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed \"" << form.getName() << "\""
                  << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't execute \"" << form.getName()
                  << "\":\n    Reason: " << e.what() << std::endl;
    }
}