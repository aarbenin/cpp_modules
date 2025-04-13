#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream fin(filename.c_str());
    if (!fin.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    if (std::getline(fin, line)) {
        std::string firstLine = line;
        trim(firstLine);
        if (firstLine.find("date") == std::string::npos &&
            firstLine.find("value") == std::string::npos &&
            firstLine.find("exchange_rate") == std::string::npos) {
            fin.clear();
            fin.seekg(0);
        }
    } else {
        std::cerr << "Error: file is empty or invalid (" << filename << ")"
                  << std::endl;
        return false;
    }

    while (std::getline(fin, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string       date;
        std::string       rateStr;

        if (!std::getline(ss, date, ',')) {
            std::cerr << "Warning: no date part in line => " << line
                      << std::endl;
            continue;
        }
        if (!std::getline(ss, rateStr)) {
            std::cerr << "Warning: no rate part in line => " << line
                      << std::endl;
            continue;
        }
        trim(date);
        trim(rateStr);

        if (!isValidDate(date)) {
            std::cerr << "Warning: invalid date => " << date << std::endl;
            continue;
        }

        double rate = 0.0;
        if (!parseDouble(rateStr, rate)) {
            std::cerr << "Warning: invalid rate => " << rateStr
                      << " in line: " << line << std::endl;
            continue;
        }

        _data[date] = rate;
    }

    fin.close();
    return true;
}

bool BitcoinExchange::getRate(const std::string& date, double& rate) const {
    std::map<std::string, double>::const_iterator it = _data.upper_bound(date);
    if (it == _data.begin()) {
        return false;
    }
    --it;
    rate = it->second;
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    int year, month, day;
    return parseDate(date, year, month, day);
}

bool BitcoinExchange::parseDate(const std::string& date, int& year, int& month,
                                int& day) {
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++) {
        if ((i == 4 || i == 7))
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    year  = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 1 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;

    static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};
    int              maxDay          = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year))
        maxDay = 29;

    if (day < 1 || day > maxDay)
        return false;

    return true;
}

bool BitcoinExchange::isLeapYear(int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

bool BitcoinExchange::parseDouble(const std::string& str, double& outVal) {
    if (str.empty())
        return false;
    char*  endPtr = nullptr;
    double val    = std::strtod(str.c_str(), &endPtr);
    if (*endPtr != '\0') {
        return false;
    }
    outVal = val;
    return true;
}

void BitcoinExchange::trim(std::string& s) {
    while (!s.empty() && (s.front() == ' ' || s.front() == '\t')) {
        s.erase(s.begin());
    }
    while (!s.empty() && (s.back() == ' ' || s.back() == '\t')) {
        s.pop_back();
    }
}
