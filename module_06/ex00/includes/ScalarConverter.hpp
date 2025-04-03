#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static bool isCharLiteral(const std::string& str);
    static bool isSingleChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isPseudoLiteral(const std::string& str);

    static void convertCharLiteral(const std::string& str);
    static void convertSingleChar(const std::string& str);
    static void convertInt(const std::string& str);
    static void convertFloat(const std::string& str);
    static void convertDouble(const std::string& str);
    static void convertPseudoLiteral(const std::string& str);

    static void printImpossible();

public:
    static void convert(const std::string& str);
};

#endif
