#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' &&
            std::isprint(static_cast<unsigned char>(literal[1])));
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty())
        return false;

    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i++;

    if (i == literal.length())
        return false;

    for (; i < literal.length(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(literal[i])))
            return false;
    }

    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty() || literal.back() != 'f')
        return false;

    std::string temp = literal.substr(0, literal.length() - 1);

    if (temp == "+inf" || temp == "-inf" || temp == "nan")
        return true;

    size_t i        = 0;
    bool   dotFound = false;

    if (temp[i] == '+' || temp[i] == '-')
        i++;

    if (i == temp.length())
        return false;

    for (; i < temp.length(); i++) {
        if (temp[i] == '.') {
            if (dotFound)
                return false;
            dotFound = true;
        } else if (!std::isdigit(static_cast<unsigned char>(temp[i]))) {
            return false;
        }
    }

    return true;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty())
        return false;
    if (literal == "+inf" || literal == "-inf" || literal == "nan")
        return true;

    size_t i        = 0;
    bool   dotFound = false;

    if (literal[i] == '+' || literal[i] == '-')
        i++;

    if (i == literal.size())
        return false;

    for (; i < literal.size(); i++) {
        if (literal[i] == '.') {
            if (dotFound)
                return false;
            dotFound = true;
        } else if (!std::isdigit(static_cast<unsigned char>(literal[i]))) {
            return false;
        }
    }

    return dotFound;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
            literal == "nanf" || literal == "+inff" || literal == "-inff" ||
            literal == "inf" || literal == "inff");
}

void ScalarConverter::convertChar(const std::string& literal) {
    char c = literal[1];

    std::cout << "char: '" << c << "'" << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;

    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;

    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string& literal) {
    try {
        std::size_t pos   = 0;
        long        value = std::stol(literal, &pos);
        if (pos != literal.size()) {
            throw std::invalid_argument("Extra characters after number");
        }

        if (value > std::numeric_limits<int>::max() ||
            value < std::numeric_limits<int>::min()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;

            float  f = static_cast<float>(value);
            double d = static_cast<double>(value);
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }

        int intValue = static_cast<int>(value);

        if (intValue >= 32 && intValue <= 126)
            std::cout << "char: '" << static_cast<char>(intValue) << "'"
                      << std::endl;
        else if (intValue >= 0 && intValue <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        std::cout << "int: " << intValue << std::endl;

        std::cout << "float: " << static_cast<float>(intValue) << ".0f"
                  << std::endl;

        std::cout << "double: " << static_cast<double>(intValue) << ".0"
                  << std::endl;
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convertFloat(const std::string& literal) {
    std::string temp = literal.substr(0, literal.length() - 1);

    if (temp == "+inf" || temp == "-inf" || temp == "nan") {
        convertPseudoLiteral(literal);
        return;
    }

    try {
        std::size_t pos   = 0;
        float       value = std::stof(temp, &pos);
        if (pos != temp.size()) {
            throw std::invalid_argument("Extra characters after float");
        }

        if (!std::isnan(value) && !std::isinf(value) && value >= 0 &&
            value <= 127) {
            char c = static_cast<char>(value);
            if (std::isprint(static_cast<unsigned char>(c)))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }

        if (std::isnan(value) || std::isinf(value) ||
            value > std::numeric_limits<int>::max() ||
            value < std::numeric_limits<int>::min()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        }

        if (std::isnan(value))
            std::cout << "float: nanf" << std::endl;
        else if (std::isinf(value) && value > 0)
            std::cout << "float: +inff" << std::endl;
        else if (std::isinf(value) && value < 0)
            std::cout << "float: -inff" << std::endl;
        else if (value == static_cast<int>(value))
            std::cout << "float: " << value << ".0f" << std::endl;
        else
            std::cout << "float: " << value << "f" << std::endl;

        double d = static_cast<double>(value);
        if (std::isnan(d))
            std::cout << "double: nan" << std::endl;
        else if (std::isinf(d) && d > 0)
            std::cout << "double: +inf" << std::endl;
        else if (std::isinf(d) && d < 0)
            std::cout << "double: -inf" << std::endl;
        else if (d == static_cast<int>(d))
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convertDouble(const std::string& literal) {
    try {
        std::size_t pos   = 0;
        double      value = std::stod(literal, &pos);
        if (pos != literal.size()) {
            throw std::invalid_argument("Extra characters after double");
        }

        if (!std::isnan(value) && !std::isinf(value) && value >= 0 &&
            value <= 127) {
            char c = static_cast<char>(value);
            if (std::isprint(static_cast<unsigned char>(c)))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }

        if (std::isnan(value) || std::isinf(value) ||
            value > std::numeric_limits<int>::max() ||
            value < std::numeric_limits<int>::min()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        }

        float f = static_cast<float>(value);
        if (std::fabs(value) > std::numeric_limits<float>::max() &&
            !std::isinf(value)) {
            std::cout << "float: impossible" << std::endl;
        } else if (std::isnan(f))
            std::cout << "float: nanf" << std::endl;
        else if (std::isinf(f) && f > 0)
            std::cout << "float: +inff" << std::endl;
        else if (std::isinf(f) && f < 0)
            std::cout << "float: -inff" << std::endl;
        else if (f == static_cast<int>(f))
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;

        if (value == static_cast<int>(value))
            std::cout << "double: " << value << ".0" << std::endl;
        else
            std::cout << "double: " << value << std::endl;
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convertPseudoLiteral(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nanf")
        std::cout << "float: nanf" << std::endl << "double: nan" << std::endl;
    else if (literal == "+inff")
        std::cout << "float: +inff" << std::endl << "double: +inf" << std::endl;
    else if (literal == "-inff")
        std::cout << "float: -inff" << std::endl << "double: -inf" << std::endl;
    else if (literal == "nan")
        std::cout << "float: nanf" << std::endl << "double: nan" << std::endl;
    else if (literal == "+inf")
        std::cout << "float: +inff" << std::endl << "double: +inf" << std::endl;
    else if (literal == "-inf")
        std::cout << "float: -inff" << std::endl << "double: -inf" << std::endl;
    else if (literal == "inf")
        std::cout << "float: inff" << std::endl << "double: inf" << std::endl;
    else if (literal == "inff")
        std::cout << "float: inff" << std::endl << "double: inf" << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    if (isPseudoLiteral(literal)) {
        convertPseudoLiteral(literal);
        return;
    }

    if (literal.length() == 1 &&
        std::isprint(static_cast<unsigned char>(literal[0])) &&
        !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    if (isChar(literal)) {
        convertChar(literal);
    } else if (isInt(literal)) {
        convertInt(literal);
    } else if (isFloat(literal)) {
        convertFloat(literal);
    } else if (isDouble(literal)) {
        convertDouble(literal);
    } else {
        try {
            std::size_t pos   = 0;
            double      value = std::stod(literal, &pos);
            if (pos != literal.size()) {
                throw std::invalid_argument("Extra characters after double");
            }

            if (!std::isnan(value) && !std::isinf(value) && value >= 0 &&
                value <= 127) {
                char c = static_cast<char>(value);
                if (std::isprint(static_cast<unsigned char>(c)))
                    std::cout << "char: '" << c << "'" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: impossible" << std::endl;
            }

            if (std::isnan(value) || std::isinf(value) ||
                value > std::numeric_limits<int>::max() ||
                value < std::numeric_limits<int>::min()) {
                std::cout << "int: impossible" << std::endl;
            } else {
                std::cout << "int: " << static_cast<int>(value) << std::endl;
            }

            float f = static_cast<float>(value);
            if (std::fabs(value) > std::numeric_limits<float>::max() &&
                !std::isinf(value)) {
                std::cout << "float: impossible" << std::endl;
            } else if (std::isnan(f))
                std::cout << "float: nanf" << std::endl;
            else if (std::isinf(f) && f > 0)
                std::cout << "float: +inff" << std::endl;
            else if (std::isinf(f) && f < 0)
                std::cout << "float: -inff" << std::endl;
            else if (f == static_cast<int>(f))
                std::cout << "float: " << f << ".0f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;

            if (value == static_cast<int>(value))
                std::cout << "double: " << value << ".0" << std::endl;
            else
                std::cout << "double: " << value << std::endl;
        } catch (...) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
}
