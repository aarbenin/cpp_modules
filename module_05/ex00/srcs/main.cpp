#include "Bureaucrat.hpp"
#include <climits>
#include <iostream>

int main() {
    std::cout << "\n===== BUREAUCRAT TESTS =====" << std::endl;

    try {
        std::cout << "\nTest 1: Creating a normal bureaucrat" << std::endl;
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        std::cout << "Decrementing grade twice..." << std::endl;
        bob.decrementGrade();
        bob.decrementGrade();
        std::cout << bob << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 2: Creating a bureaucrat with too high grade (0)"
                  << std::endl;
        Bureaucrat alice("Alice", 0);
        std::cout << "This line should not be reached" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 3: Creating a bureaucrat with too low grade (151)"
                  << std::endl;
        Bureaucrat charlie("Charlie", 151);
        std::cout << "This line should not be reached" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 4: Trying to increment from highest grade (1)"
                  << std::endl;
        Bureaucrat dave("Dave", 1);
        std::cout << dave << std::endl;
        dave.incrementGrade();
        std::cout << "This line should not be reached." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 5: Trying to decrement from lowest grade (150)"
                  << std::endl;
        Bureaucrat eve("Eve", 150);
        std::cout << eve << std::endl;
        eve.decrementGrade();
        std::cout << "This line should not be reached." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 6: Extreme values - INT_MIN" << std::endl;
        Bureaucrat extreme("Extreme", INT_MIN);
        std::cout << "This line should not be reached." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 7: Extreme values - INT_MAX" << std::endl;
        Bureaucrat extreme("Extreme", INT_MAX);
        std::cout << "This line should not be reached." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 8: Reaching boundary values during operations"
                  << std::endl;

        Bureaucrat almostTop("AlmostTop", 2);
        std::cout << almostTop << std::endl;

        almostTop.incrementGrade();
        std::cout << "After first increment: " << almostTop << std::endl;

        std::cout << "Trying to increment past the top limit..." << std::endl;
        almostTop.incrementGrade();
        std::cout << "This line should not be reached" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat almostBottom("AlmostBottom", 149);
        std::cout << almostBottom << std::endl;

        almostBottom.decrementGrade();
        std::cout << "After first decrement: " << almostBottom << std::endl;

        std::cout << "Trying to decrement past the bottom limit..."
                  << std::endl;
        almostBottom.decrementGrade();
        std::cout << "This line should not be reached" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== TESTS COMPLETED =====\n" << std::endl;

    return 0;
}