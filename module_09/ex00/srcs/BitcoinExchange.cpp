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
    if (!std::getline(fin, line)) {
        std::cerr << "Error: file is empty or invalid." << std::endl;
        return false;
    }

    while (std::getline(fin, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string       date;
        std::string       rateStr;

        if (!std::getline(ss, date, ',')) {
            continue;
        }
        if (!std::getline(ss, rateStr)) {
            continue;
        }

        if (!isValidDate(date)) {
            continue;
        }

        double rate = std::atof(rateStr.c_str());
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
        if (i == 4 || i == 7)
            continue; // это '-'
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
