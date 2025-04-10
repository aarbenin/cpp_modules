#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    // Orthodox Canonical Form
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    // Загрузка базы (например, "data.csv")
    bool loadDatabase(const std::string &filename);

    // Найти в базе «ближайшую НЕ превосходящую дату».
    // Если нашли, записать курс в rate и вернуть true, иначе вернуть false.
    bool getRate(const std::string &date, double &rate) const;

    // Проверка даты на валидность (учитываем год/месяц/день, високосность)
    static bool isValidDate(const std::string &date);

private:
    // Собственно, данные: date(YYYY-MM-DD) -> exchange rate
    std::map<std::string, double> _data;

    // Вспомогательная функция (вынесена для наглядности, чтобы isValidDate было покороче)
    static bool parseDate(const std::string &date, int &year, int &month, int &day);
    static bool isLeapYear(int year);
};

#endif
