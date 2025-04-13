#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

static void trim(std::string& s) {
    while (!s.empty() && (s.front() == ' ' || s.front() == '\t')) {
        s.erase(s.begin());
    }
    while (!s.empty() && (s.back() == ' ' || s.back() == '\t')) {
        s.pop_back();
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file. (Usage: ./btc <input_file>)"
                  << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.loadDatabase("data.csv")) {
        std::cerr << "Error: could not load data.csv" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);
    if (!fin.is_open()) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return 1;
    }

    {
        std::streampos pos = fin.tellg();
        std::string    firstLine;
        if (std::getline(fin, firstLine)) {
            std::string temp = firstLine;
            trim(temp);
            if (temp.find("date") == std::string::npos ||
                temp.find("value") == std::string::npos) {
                fin.clear();
                fin.seekg(pos);
            }
        } else {
            std::cerr << "Error: input file is empty." << std::endl;
            return 1;
        }
    }

    std::string line;
    while (std::getline(fin, line)) {
        if (line.empty())
            continue;

        size_t pos = line.find('|');
        if (pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date     = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);

        trim(date);
        trim(valueStr);

        if (!BitcoinExchange::isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value = 0.0;
        {
            char*  endPtr = nullptr;
            double tmp    = std::strtod(valueStr.c_str(), &endPtr);
            if (*endPtr != '\0') {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            value = tmp;
        }

        if (value < 0.0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000.0) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = 0.0;
        if (!btc.getRate(date, rate)) {
            std::cerr << "Error: no exchange rate available for this date => "
                      << date << std::endl;
            continue;
        }

        double result = rate * value;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    fin.close();
    return 0;
}
