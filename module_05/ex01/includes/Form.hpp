#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const noexcept;
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const noexcept;
    };

    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif