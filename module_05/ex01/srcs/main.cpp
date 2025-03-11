#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <climits>
#include <iomanip>
#include <iostream>

void printSeparator(char c = '-', int length = 50) {
    std::cout << std::string(length, c) << std::endl;
}

void printTestHeader(const std::string& testName) {
    std::cout << "\n";
    printSeparator('=');
    std::cout << "TEST: " << testName << std::endl;
    printSeparator('=');
}

int main() {
    std::cout << "\n========== BUREAUCRAT AND FORM TESTS ==========\n"
              << std::endl;

    try {
        printTestHeader("Creating and signing a normal form");

        Form basicForm("Basic form", 50, 25);
        std::cout << "Created form: " << std::endl;
        std::cout << "  " << basicForm << std::endl;

        Bureaucrat bob("Bob", 30);
        std::cout << "\nCreated bureaucrat: " << std::endl;
        std::cout << "  " << bob << std::endl;

        std::cout << "\nAttempting to sign the form:" << std::endl;
        bob.signForm(basicForm);

        std::cout << "\nForm status after signing attempt:" << std::endl;
        std::cout << "  " << basicForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        printTestHeader("Attempting to sign a form with insufficient grade");

        Form highForm("High clearance form", 20, 10);
        std::cout << "Created form: " << std::endl;
        std::cout << "  " << highForm << std::endl;

        Bureaucrat charlie("Charlie", 30);
        std::cout << "\nCreated bureaucrat: " << std::endl;
        std::cout << "  " << charlie << std::endl;

        std::cout << "\nAttempting to sign the form:" << std::endl;
        charlie.signForm(highForm);

        std::cout << "\nForm status after signing attempt:" << std::endl;
        std::cout << "  " << highForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        printTestHeader("Creating a form with invalid grade (too high)");

        std::cout << "Attempting to create a form with sign grade = 0:"
                  << std::endl;
        Form invalidForm("Invalid Form", 0, 50);

        std::cout << "This line should not be reached" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        printTestHeader("Creating a form with invalid grade (too low)");

        std::cout << "Attempting to create a form with execute grade = 151:"
                  << std::endl;
        Form invalidForm("Invalid form", 50, 151);

        std::cout << "This line should not be reached" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        printTestHeader("Signing an already signed form");

        Form simpleForm("Simple form", 100, 100);
        std::cout << "Created form: " << std::endl;
        std::cout << "  " << simpleForm << std::endl;

        Bureaucrat alice("Alice", 1);
        std::cout << "\nCreated bureaucrat: " << std::endl;
        std::cout << "  " << alice << std::endl;

        std::cout << "\nFirst signing attempt:" << std::endl;
        alice.signForm(simpleForm);

        std::cout << "\nForm status after first signing:" << std::endl;
        std::cout << "  " << simpleForm << std::endl;

        std::cout << "\nSecond signing attempt:" << std::endl;
        alice.signForm(simpleForm);
    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        printTestHeader("Different bureaucrats interacting with a form");

        Form secretForm("Secret form", 30, 5);
        std::cout << "Created form: " << std::endl;
        std::cout << "  " << secretForm << std::endl;

        Bureaucrat lowRank("LowRank", 100);
        Bureaucrat midRank("MidRank", 30);
        Bureaucrat highRank("HighRank", 1);

        std::cout << "\nCreated bureaucrats:" << std::endl;
        std::cout << "  " << lowRank << std::endl;
        std::cout << "  " << midRank << std::endl;
        std::cout << "  " << highRank << std::endl;

        std::cout << "\nLow rank bureaucrat signing attempt:" << std::endl;
        lowRank.signForm(secretForm);

        std::cout << "\nMid rank bureaucrat signing attempt:" << std::endl;
        midRank.signForm(secretForm);

        std::cout << "\nHigh rank bureaucrat signing attempt:" << std::endl;
        highRank.signForm(secretForm);

        std::cout << "\nFinal form status:" << std::endl;
        std::cout << "  " << secretForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }

    printSeparator('=', 50);
    std::cout << "TESTS COMPLETED" << std::endl;
    printSeparator('=', 50);
    std::cout << std::endl;

    return 0;
}