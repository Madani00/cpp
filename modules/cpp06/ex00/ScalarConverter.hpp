#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>


class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other); 
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(std::string literal);
};


