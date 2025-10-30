#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int factBits; 
    public:
        // Orthodox Canonical Form
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other);  //  Copy assignment operator

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};



#endif


