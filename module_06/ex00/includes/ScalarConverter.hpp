#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isPseudoLiteral(const std::string& literal);

    static void convertChar(const std::string& literal);
    static void convertInt(const std::string& literal);
    static void convertFloat(const std::string& literal);
    static void convertDouble(const std::string& literal);
    static void convertPseudoLiteral(const std::string& literal);

public:
    static void convert(const std::string& literal);
};

#endif
