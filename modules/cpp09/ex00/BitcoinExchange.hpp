#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, double> _data;

    bool isValidDate(const std::string& date) const;
    bool parseValue(const std::string& valueStr, double& value) const;
    bool getRateForDate(const std::string& date, double& rate) const;
    std::string trim(const std::string& str) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    bool loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename) const;
};