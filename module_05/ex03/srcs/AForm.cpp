#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const noexcept {
    return "grade is too high (must be at least 1)";
}

const char* AForm::GradeTooLowException::what() const noexcept {
    return "grade is too low for this operation";
}

const char* AForm::NotSignedException::what() const noexcept {
    return "form is not signed";
}

AForm::AForm()
    : _name("Default Form"),
      _isSigned(false),
      _gradeToSign(150),
      _gradeToExecute(150),
      _target("default") {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _target("default") {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute,
             const std::string& target)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute),
      _target(other._target) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

const std::string& AForm::getTarget() const {
    return _target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!_isSigned)
        throw NotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "  Form:             " << form.getName() << "\n"
       << "  Status:           " << (form.isSigned() ? "Signed" : "Not signed")
       << "\n"
       << "  Grade to sign:    " << form.getGradeToSign() << "\n"
       << "  Grade to execute: " << form.getGradeToExecute();
    return os;
}