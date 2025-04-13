#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename);

    bool getRate(const std::string& date, double& rate) const;

    static bool isValidDate(const std::string& date);

private:
    std::map<std::string, double> _data;

    static bool parseDate(const std::string& date, int& year, int& month,
                          int& day);
    static bool isLeapYear(int year);

    static bool parseDouble(const std::string& str, double& outVal);
    static void trim(std::string& s);
};

#endif
