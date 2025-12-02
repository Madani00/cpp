#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter Copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
    std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
    if (this != &other) {
        
    }
    return *this;
}

void printConversions(double d)
{
    // -128 < std::numeric_limits<char>::min() // prevent negative value
    //  std::numeric_limits<unsigned char>::max() > 255 // prevent potive values
    // d = 0.0 / 0.0;
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<unsigned char>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        char c = static_cast<char>(d);
        if (std::isprint((c)))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }

    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inff" : "inff") << std::endl;
    else {
        float f = static_cast<float>(d);
        std::stringstream oss;
        if (std::floor(f) == f) { // 42.0 or 45
            oss << std::fixed << std::setprecision(1) << f << "f";
        }
        else
            oss << std::setprecision(8) << f << "f";
        std::cout << oss.str() << std::endl; 
    }

    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inf" : "inf") << std::endl;
    else {
        std::stringstream oss;
        if (std::floor(d) == d)
            oss << std::fixed << std::setprecision(1) << d;
        else
            oss << std::setprecision(8) << d;
        std::cout << oss.str() << std::endl;
    }
}
// -inff, +inff, nanf. 
// -inf, +inf, nan.

bool handleLiterals(const std::string &literal)
{
    if (!(literal == "-inff" || literal == "+inff" || literal == "nanf" || \
            literal == "-inf"  || literal == "+inf"  || literal == "nan"))
        return false;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    return true;
}

// 42abc or 12.3.4 or "42 " or 1.  <===   i need to fix them
// +12 , -12 correct
// 42a nooooo   / 42ff
//   and 42f
// -.45

bool checkValid(const std::string &literal) {
    size_t i = 0;
    size_t countDot = 0;
    size_t strSize = literal.length();

    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (literal[i] == '.' || literal[strSize - 1] == '.' || \
        (literal[strSize - 1] != 'f' && !std::isdigit(literal[strSize - 1])))
        return true;
    while (i < strSize)
    {
        if (!std::isdigit(literal[i]) && literal[i] != '.' && i < strSize - 1)
            return true;
        if (literal[i] == '.')
            countDot++;
        i++;
    }
    if (countDot > 1)
        return true;
    return false;
}
void ScalarConverter::convert(std::string literal)
{
    // if (literal.empty())
    //     return;

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        printConversions(static_cast<double>(literal[0]));
        return;
    }

    else if (handleLiterals(literal))
        return ;

    std::stringstream str(literal);
    double dbl;
    str >> dbl;
    if ((str.fail() && literal.size() > 1) || checkValid(literal)) {
        std::cout << "you provided INVALID input!!" << std::endl;
        return ;
    }
    printConversions(dbl);
}