#include "BitcoinExchange.hpp"

// static bool isLeapYear(int year)
// {
//     return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
// }

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            continue;
        }

        std::string date = trim(line.substr(0, commaPos)); // 2009-01-02
        std::string priceStr = trim(line.substr(commaPos + 1)); // 00
        std::stringstream ss(priceStr);
        double rate;
        char leftover;

        if (!isValidDate(date)) {
            continue;
        }
  
        if (!(ss >> rate) || (ss >> leftover)) { // leftover for "12.5abc" or "12.5 99"
            continue;
        }

        _data[date] = rate;
    }
    file.close();
    return !_data.empty();
}

std::string BitcoinExchange::trim(const std::string& str) const
{
    std::size_t start = 0;
    std::size_t end = str.size();

    while (start < end && std::isspace(str[start])) { // static_cast<unsigned char>(
        ++start; 
    }
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }
    return str.substr(start, end - start);
}

// 2009-01-02
bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    for (std::size_t i = 0; i < date.size(); i++) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (!std::isdigit(static_cast<unsigned char>(date[i]))) {
            return false;
        }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || year < 2009 || year > 2025) {
        return false;
    }

    int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day >= 1 && day <= daysInMonth[month - 1];
}

bool BitcoinExchange::parseValue(const std::string& valueStr, double& value) const
{
    std::stringstream ss(valueStr);
    char leftover;

    if (!(ss >> value) || (ss >> leftover)) {
        return false;
    }
    return true;
}

bool BitcoinExchange::getRateForDate(const std::string& date, double& rate) const
{
    std::map<std::string, double>::const_iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date) {
        rate = it->second;
        return true;
    }
    if (it == _data.begin()) {
        return false;
    }

    --it;
    rate = it->second;
    return true;
}

void BitcoinExchange::processInputFile(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) { 
            continue;
        }

        std::size_t sep = line.find("|");
        if (sep == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, sep)); // "2011-01-03 " (Notice the space at the end)
        std::string valueStr = trim(line.substr(sep + 1)); // " 1.2"
        double value;
        double rate;

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!parseValue(valueStr, value)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        if (!getRateForDate(date, rate)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}