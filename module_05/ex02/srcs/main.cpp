#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>

void printSeparator(char c = '-', int length = 70) {
    std::cout << std::string(length, c) << std::endl;
}

void printTestHeader(const std::string& testName) {
    std::cout << "\n";
    printSeparator('=');
    std::cout << "TEST: " << testName << std::endl;
    printSeparator('=');
}

int main() {
    std::cout << "\n=========== BUREAUCRAT AND FORMS TESTS ===========\n" << std::endl;
    
    Bureaucrat intern("Intern", 150);
    Bureaucrat secretary("Secretary", 120);
    Bureaucrat clerk("Clerk", 70);
    Bureaucrat executive("Executive", 20);
    Bureaucrat president("President", 1);
    
    printTestHeader("ShrubberyCreationForm - basic tests");
    try {
        ShrubberyCreationForm shrubberyForm("garden");
        std::cout << shrubberyForm << std::endl;
        
        std::cout << "\nTrying to execute unsigned form:" << std::endl;
        clerk.executeForm(shrubberyForm);
        
        std::cout << "\nSigning the form:" << std::endl;
        secretary.signForm(shrubberyForm);

        std::cout << "\nExecuting the form:" << std::endl;
        clerk.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printTestHeader("RobotomyRequestForm - basic tests");
    try {
        RobotomyRequestForm robotomyForm("Bender");
        std::cout << robotomyForm << std::endl;
        
        std::cout << "\nTrying to sign with insufficient grade:" << std::endl;
        secretary.signForm(robotomyForm);
        
        std::cout << "\nSigning with sufficient grade:" << std::endl;
        clerk.signForm(robotomyForm);

        std::cout << "\nTrying to execute with insufficient grade:" << std::endl;
        clerk.executeForm(robotomyForm);
        
        std::cout << "\nExecuting with sufficient grade:" << std::endl;
        executive.executeForm(robotomyForm);
        
        std::cout << "\nExecuting again:" << std::endl;
        executive.executeForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printTestHeader("PresidentialPardonForm - basic tests");
    try {
        PresidentialPardonForm pardonForm("Bob Papers");
        std::cout << pardonForm << std::endl;
        
        std::cout << "\nSigning the form:" << std::endl;
        executive.signForm(pardonForm);
        
        std::cout << "\nTrying to execute with insufficient grade:" << std::endl;
        executive.executeForm(pardonForm);
        
        std::cout << "\nExecuting with president:" << std::endl;
        president.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printTestHeader("Error handling tests");
    try {
        ShrubberyCreationForm errorForm("error_test");
        std::cout << "Form with unsigned status:" << std::endl;
        std::cout << errorForm << std::endl;
        
        std::cout << "\nTrying to execute with lowest rank and unsigned:" << std::endl;
        intern.executeForm(errorForm);
        secretary.signForm(errorForm);
        
        std::cout << "\nTrying to execute with insufficient grade:" << std::endl;
        intern.executeForm(errorForm);
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printTestHeader("Copy constructors and assignment operators");
    try {
        ShrubberyCreationForm originalShrubbery("garden_original");
        std::cout << "Original shrubbery form:" << std::endl;
        std::cout << originalShrubbery << std::endl;
        
        std::cout << "\nSigning the original shrubbery form:" << std::endl;
        secretary.signForm(originalShrubbery);
        
        std::cout << "\nCreating a copy of the shrubbery form:" << std::endl;
        ShrubberyCreationForm copiedShrubbery(originalShrubbery);
        std::cout << "Copied shrubbery form:" << std::endl;
        std::cout << copiedShrubbery << std::endl;
        std::cout << "Is copied form signed: " << (copiedShrubbery.isSigned() ? "Yes" : "No") << std::endl;
        
        std::cout << "\nCreating a default shrubbery form and assigning to it:" << std::endl;
        ShrubberyCreationForm assignedShrubbery;
        std::cout << "Before assignment:" << std::endl;
        std::cout << assignedShrubbery << std::endl;
        
        assignedShrubbery = originalShrubbery;
        std::cout << "After assignment:" << std::endl;
        std::cout << assignedShrubbery << std::endl;
        std::cout << "Is assigned form signed: " << (assignedShrubbery.isSigned() ? "Yes" : "No") << std::endl;
        
        std::cout << "\nTesting copy/assignment with robotomy form:" << std::endl;
        RobotomyRequestForm originalRobotomy("robot_original");
        clerk.signForm(originalRobotomy);
        
        RobotomyRequestForm copiedRobotomy(originalRobotomy);
        RobotomyRequestForm assignedRobotomy;
        assignedRobotomy = originalRobotomy;
        
        std::cout << "Original signed: " << (originalRobotomy.isSigned() ? "Yes" : "No") << std::endl;
        std::cout << "Copied signed: " << (copiedRobotomy.isSigned() ? "Yes" : "No") << std::endl;
        std::cout << "Assigned signed: " << (assignedRobotomy.isSigned() ? "Yes" : "No") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    return 0;
}