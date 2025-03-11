#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

const char*
ShrubberyCreationForm::FileOperationException::what() const noexcept {
    return "error during file operation";
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery creation form", SIGN_GRADE, EXEC_GRADE, "default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery creation form", SIGN_GRADE, EXEC_GRADE, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);

    std::string   filename = getTarget() + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
        throw FileOperationException();
    }

    outfile << "\n\n\n\n\n               ,@@@@@@@,                                ,@@@@@@@," << std::endl;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.          ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o      ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'    ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'       `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outfile << "       |o|        | |         | |             |o|        | |         | |" << std::endl;
    outfile << "       |.|        | |         | |             |.|        | |         | |" << std::endl;
    outfile << "     \\\\/._\\//_/__/  ,\\_//__\\\\/.  \\_//__\\__/ \\\\/._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

    outfile.close();

    std::cout << "🌳 Created shrubbery in file: " << filename << std::endl;
}