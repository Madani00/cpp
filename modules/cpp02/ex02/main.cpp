
#include "Fixed.hpp"

int main( void ) {
    // // Fixed a;
    // // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // // std::cout << Fixed::max( a, b ) << std::endl;
    Fixed ma(8.5f);
    Fixed da(4);
    std::cout << ma - da  << std::endl;
    return 0;
}