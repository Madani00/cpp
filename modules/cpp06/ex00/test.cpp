#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>


static void printConversions(double d)
{
    // char
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<unsigned char>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        char c = static_cast<char>(d);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }

    // int
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    // float
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inff" : "inff") << std::endl;
    else {
        float f = static_cast<float>(d);
        std::ostringstream oss;
        if (std::floor(f) == f)
            oss << std::fixed << std::setprecision(1) << f << "f";
        else
            oss << std::setprecision(6) << f << "f";
        std::cout << oss.str() << std::endl;
    }

    // double
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inf" : "inf") << std::endl;
    else {
        std::ostringstream oss;
        if (std::floor(d) == d)
            oss << std::fixed << std::setprecision(1) << d;
        else
            oss << std::setprecision(6) << d;
        std::cout << oss.str() << std::endl;
    }
}

void ScalarConverter::convert(std::string literal)
{
    if (literal.empty())
        return;

    // single non-digit char -> treat as char literal
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        double d = static_cast<double>(literal[0]);
        printConversions(d);
        return;
    }

    // strip trailing 'f' for float literals like "42.0f" or "nanf"
    std::string toParse = literal;
    if (toParse.back() == 'f' && toParse.size() > 1)
        toParse = toParse.substr(0, toParse.size() - 1);

    double value;
    try {
        size_t idx = 0;
        value = std::stod(toParse, &idx);
        if (idx != toParse.size()) {
            // leftover characters -> invalid
            throw std::invalid_argument("extra chars");
        }
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printConversions(value);
}

// tests

// Example values that make isnan(d) == true:

// d = 0.0 / 0.0 → NaN
// d = std::sqrt(-4.0) → NaN
// d = std::log(-1.0) → NaN

// ✔ Example values that make isinf(d) == true:

// d = 1.0 / 0.0 → +inf
// d = -1.0 / 0.0 → −inf
// d = 1e309 (too big for double) → +inf
// d = -1e309 → −inf


// tests
// 42f and 42.0f , many compilers do accept 42.f or 42.0f
// 3.4028235e+38f (approx FLT_MAX)
// 1.0e39f
// 1e3 == 1000
// 42abc or 12.3.4 or "42 "   <=== i need to fix them
// 0.0000000000000001 (very small double)
