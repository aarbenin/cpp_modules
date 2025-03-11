#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy request form", SIGN_GRADE, EXEC_GRADE, "default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy request form", SIGN_GRADE, EXEC_GRADE, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);

    std::cout << "🔊 *Drilling noises* Bzzzz! Whirrrr! Drrrrr!" << std::endl;

    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(0)));
        seeded = true;
    }

    if (std::rand() % 2) {
        std::cout << "🤖 " << getTarget()
                  << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "💥 Robotomy failed! " << getTarget()
                  << " remains unchanged." << std::endl;
    }
}