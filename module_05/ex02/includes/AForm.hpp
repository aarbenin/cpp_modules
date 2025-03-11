#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const noexcept;
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const noexcept;
    };

    class NotSignedException : public std::exception {
    public:
        virtual const char* what() const noexcept;
    };

    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;
    const std::string& getTarget() const;

    void         		beSigned(const Bureaucrat& bureaucrat);
    virtual void 		execute(const Bureaucrat& executor) const = 0;

protected:
    void 				checkExecution(const Bureaucrat& executor) const;

    AForm(const std::string& name, int gradeToSign, int gradeToExecute,
          const std::string& target);

private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    const std::string _target;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif