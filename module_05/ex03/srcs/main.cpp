#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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
    std::cout << "\n=========== INTERN AND FORMS TESTS ===========\n" << std::endl;
    
    Intern someRandomIntern;
    
    printTestHeader("Creating ShrubberyCreationForm using Intern");
    try {
        AForm* form = someRandomIntern.makeForm("shrubbery creation", "Garden");
        std::cout << "\nForm details:" << std::endl;
        std::cout << *form << std::endl;
        
        Bureaucrat secretary("Secretary", 120);
        std::cout << "\nCreated bureaucrat:" << std::endl;
        std::cout << secretary << std::endl;
        
        std::cout << "\nSigning the form:" << std::endl;
        secretary.signForm(*form);
        
        std::cout << "\nExecuting the form:" << std::endl;
        secretary.executeForm(*form);

        delete form;
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printTestHeader("Creating RobotomyRequestForm using Intern");
    try {
        AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "\nForm details:" << std::endl;
        std::cout << *form << std::endl;
        
        Bureaucrat clerk("Clerk", 70);
        Bureaucrat executive("Executive", 40);
        
        std::cout << "\nCreated bureaucrats:" << std::endl;
        std::cout << clerk << std::endl;
        std::cout << executive << std::endl;
        
        std::cout << "\nSigning the form:" << std::endl;
        clerk.signForm(*form);
        
        std::cout << "\nTrying to execute with Clerk:" << std::endl;
        clerk.executeForm(*form);
        
        std::cout << "\nExecuting with Executive:" << std::endl;
        executive.executeForm(*form);
        
        delete form;
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printTestHeader("Creating PresidentialPardonForm using Intern");
    try {
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Bob Papers");
        std::cout << "\nForm details:" << std::endl;
        std::cout << *form << std::endl;
        
        Bureaucrat executive("Executive", 20);
        Bureaucrat president("President", 1);
        
        std::cout << "\nCreated bureaucrats:" << std::endl;
        std::cout << executive << std::endl;
        std::cout << president << std::endl;
        
        std::cout << "\nSigning the form:" << std::endl;
        executive.signForm(*form);
        
        std::cout << "\nExecuting the form:" << std::endl;
        president.executeForm(*form);
        
        delete form;
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printTestHeader("Trying to create an unknown form");
    try {
        std::cout << "Requesting unknown form type:" << std::endl;
        AForm* form = someRandomIntern.makeForm("coffee order", "Office");
        
        std::cout << "Form details:" << std::endl;
        std::cout << *form << std::endl;
        
        delete form;
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printTestHeader("Example from the assignment");
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        std::cout << "Creating robotomy request for Bender:" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        std::cout << "\nForm details:" << std::endl;
        std::cout << *rrf << std::endl;
        
        delete rrf;
    } catch (const std::exception& e) {
        std::cerr << "❗ EXCEPTION: " << e.what() << std::endl;
    }
    
    printSeparator('=', 70);
    std::cout << "ALL TESTS COMPLETED SUCCESSFULLY" << std::endl;
    printSeparator('=', 70);
    std::cout << std::endl;
    
    return 0;
}