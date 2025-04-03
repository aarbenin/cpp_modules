#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <stdexcept>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(const std::string& str) {
    return str.size() == 3 && str.front() == '\'' && str.back() == '\'' &&
           std::isprint(static_cast<unsigned char>(str[1]));
}

bool ScalarConverter::isSingleChar(const std::string& str) {
    return str.size() == 1 &&
           std::isprint(static_cast<unsigned char>(str[0])) &&
           !std::isdigit(static_cast<unsigned char>(str[0]));
}

bool ScalarConverter::isInt(const std::string& str) {
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++;
    if (i == str.size())
        return false;
    for (; i < str.size(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str == "+inff" || str == "-inff" || str == "nanf")
        return true;

    if (str.size() < 2 || str.back() != 'f')
        return false;

    std::string number = str.substr(0, str.size() - 1);
    size_t      dot    = number.find('.');
    if (dot == std::string::npos)
        return false;

    bool hasDigit = false;
    for (char ch : number) {
        if (std::isdigit(ch))
            hasDigit = true;
    }
    if (!hasDigit)
        return false;

    size_t pos = 0;
    try {
        std::stof(number, &pos);
    } catch (...) {
        return false;
    }
    return (pos == number.size());
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str == "+inf" || str == "-inf" || str == "nan")
        return true;

    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos || dotPos != str.rfind('.'))
        return false;

    bool hasDigit = false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (std::isdigit(str[i])) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit)
        return false;

    size_t pos = 0;
    try {
        std::stod(str, &pos);
    } catch (...) {
        return false;
    }

    return pos == str.size();
}

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" ||
            str == "+inff" || str == "-inff" || str == "inf" || str == "inff");
}

void ScalarConverter::printImpossible() {
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: impossible\n"
              << "double: impossible\n";
}

void ScalarConverter::convertCharLiteral(const std::string& str) {
    char c = str[1];
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::convertSingleChar(const std::string& str) {
    char c = str[0];
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::convertInt(const std::string& str) {
    try {
        std::size_t pos   = 0;
        int         value = std::stoi(str, &pos);
        if (pos != str.size())
            throw std::invalid_argument("Extra characters");
        char c;
        if (value >= 0 && value <= 127 &&
            std::isprint(static_cast<unsigned char>(value)))
            c = static_cast<char>(value);
        else if (value >= 0 && value <= 127)
            c = 0;
        else
            c = 0;
        std::cout << "char: ";
        if (value >= 0 && value <= 127) {
            if (std::isprint(c))
                std::cout << "'" << c << "'";
            else
                std::cout << "Non displayable";
        } else {
            std::cout << "impossible";
        }
        std::cout << "\n";
        std::cout << "int: " << value << "\n";
        std::cout << "float: " << static_cast<float>(value) << ".0f\n";
        std::cout << "double: " << static_cast<double>(value) << ".0\n";
    } catch (...) {
        printImpossible();
    }
}

void ScalarConverter::convertFloat(const std::string& str) {
    std::string number = str.substr(0, str.size() - 1);
    if (number == "+inf" || number == "-inf" || number == "nan") {
        convertPseudoLiteral(str);
        return;
    }
    try {
        std::size_t pos   = 0;
        float       value = std::stof(number, &pos);
        if (pos != number.size())
            throw std::invalid_argument("Extra characters after float");
        std::cout << "char: ";
        if (!std::isnan(value) && !std::isinf(value) && value >= 0.0f &&
            value <= 127.0f) {
            char c = static_cast<char>(value);
            if (std::isprint(static_cast<unsigned char>(c)))
                std::cout << "'" << c << "'";
            else
                std::cout << "Non displayable";
        } else {
            std::cout << "impossible";
        }
        std::cout << "\n";
        std::cout << "int: ";
        if (std::isnan(value) || std::isinf(value) ||
            value > static_cast<float>(std::numeric_limits<int>::max()) ||
            value < static_cast<float>(std::numeric_limits<int>::min()))
            std::cout << "impossible";
        else
            std::cout << static_cast<int>(value);
        std::cout << "\n";
        std::cout << "float: ";
        if (std::isnan(value))
            std::cout << "nanf";
        else if (std::isinf(value))
            std::cout << (value > 0 ? "+inff" : "-inff");
        else {
            if (static_cast<int>(value) == value)
                std::cout << value << ".0f";
            else
                std::cout << value << "f";
        }
        std::cout << "\n";
        double dValue = static_cast<double>(value);
        std::cout << "double: ";
        if (std::isnan(dValue))
            std::cout << "nan";
        else if (std::isinf(dValue))
            std::cout << (dValue > 0 ? "+inf" : "-inf");
        else {
            if (static_cast<int>(dValue) == dValue)
                std::cout << dValue << ".0";
            else
                std::cout << dValue;
        }
        std::cout << "\n";
    } catch (...) {
        printImpossible();
    }
}

void ScalarConverter::convertDouble(const std::string& str) {
    try {
        std::size_t pos   = 0;
        double      value = std::stod(str, &pos);
        if (pos != str.size())
            throw std::invalid_argument("Extra characters after double");
        // char
        std::cout << "char: ";
        if (!std::isnan(value) && !std::isinf(value) && value >= 0.0 &&
            value <= 127.0) {
            char c = static_cast<char>(value);
            if (std::isprint(static_cast<unsigned char>(c)))
                std::cout << "'" << c << "'";
            else
                std::cout << "Non displayable";
        } else {
            std::cout << "impossible";
        }
        std::cout << "\n";
        std::cout << "int: ";
        if (std::isnan(value) || std::isinf(value) ||
            value > static_cast<double>(std::numeric_limits<int>::max()) ||
            value < static_cast<double>(std::numeric_limits<int>::min()))
            std::cout << "impossible";
        else
            std::cout << static_cast<int>(value);
        std::cout << "\n";
        float fValue = static_cast<float>(value);
        std::cout << "float: ";
        if (!std::isinf(value) &&
            std::fabs(value) >
                static_cast<double>(std::numeric_limits<float>::max()))
            std::cout << "impossible";
        else if (std::isnan(fValue))
            std::cout << "nanf";
        else if (std::isinf(fValue))
            std::cout << (fValue > 0 ? "+inff" : "-inff");
        else {
            if (static_cast<int>(fValue) == fValue)
                std::cout << fValue << ".0f";
            else
                std::cout << fValue << "f";
        }
        std::cout << "\n";
        std::cout << "double: ";
        if (std::isnan(value))
            std::cout << "nan";
        else if (std::isinf(value))
            std::cout << (value > 0 ? "+inf" : "-inf");
        else {
            if (static_cast<int>(value) == value)
                std::cout << value << ".0";
            else
                std::cout << value;
        }
        std::cout << "\n";
    } catch (...) {
        printImpossible();
    }
}

void ScalarConverter::convertPseudoLiteral(const std::string& str) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    if (str == "nanf" || str == "nan")
        std::cout << "float: nanf\n" << "double: nan\n";
    else if (str == "+inff" || str == "+inf")
        std::cout << "float: +inff\n" << "double: +inf\n";
    else if (str == "-inff" || str == "-inf")
        std::cout << "float: -inff\n" << "double: -inf\n";
    else if (str == "inf" || str == "inff")
        std::cout << "float: inff\n" << "double: inf\n";
}

void ScalarConverter::convert(const std::string& str) {
    if (str.empty()) {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }
    if (isPseudoLiteral(str)) {
        convertPseudoLiteral(str);
        return;
    }

    if (isSingleChar(str)) {
        convertSingleChar(str);
        return;
    }

    if (isCharLiteral(str)) {
        convertCharLiteral(str);
        return;
    }
    if (isInt(str)) {
        convertInt(str);
        return;
    }
    if (isFloat(str)) {
        convertFloat(str);
        return;
    }
    if (isDouble(str)) {
        convertDouble(str);
        return;
    }
    try {
        std::size_t pos = 0;
        std::stod(str, &pos);
        if (pos != str.size())
            throw std::invalid_argument("Extra characters");
        convertDouble(str);
    } catch (...) {
        printImpossible();
    }
}
