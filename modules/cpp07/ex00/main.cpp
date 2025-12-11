#include "whatever.hpp"
#include <iostream>

int main( void ) {
    int a = 3;
    int b = 8;
    std::string c = "chaine1";
    std::string d = "chaine2";
    int &ref = a;
    int &ref2 = b;
    int *nm = new int(45);
    int *nm2 = new int(500);

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    ::swap(c, d);
    std::cout << "\nc = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    ::swap(ref, ref2);
    std::cout << "\nref = " << ref << ", ref2 = " << ref2 << std::endl;
    std::cout << "min( ref, ref2 ) = " << ::min( ref, ref2 ) << std::endl;
    std::cout << "max( ref, ref2 ) = " << ::max( ref, ref2 ) << std::endl;


    std::cout << "\nbefore nm = " << nm << " ,before nm2 = " << nm2 << std::endl;
    ::swap(nm, nm2);
    std::cout << "nm = " << nm << ", nm2 = " << nm2 << std::endl;
    std::cout << "min( nm, nm2 ) = " << ::min( nm, nm2 ) << std::endl;
    std::cout << "max( nm, nm2 ) = " << ::max( nm, nm2 ) << std::endl;

    delete nm;
    delete nm2;

    return 0;
}

