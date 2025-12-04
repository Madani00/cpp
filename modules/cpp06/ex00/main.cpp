#include "ScalarConverter.hpp"

int main(int ac, char *av[]) {

    if (ac != 2) {
        std::cout << "you should provide the argument --> (char / int / float / double)" << std::endl; 
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return (0);
}



























// tests
// 42f and 42.0f , many compilers do accept 42.f or 42.0f
// 3.4028235e+38f (approx FLT_MAX)
// 1.0e39f
// 1e3 == 1000
// 42abc or 12.3.4 or "42 "   <=== i need to fix them
// 0.0000000000000001 (very small double)
