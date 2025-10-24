#ifndef FIXED_H
#define FIXED_H

#include <math.h>
#include <iostream>


class Fixed
{
    private:
        int value;
        static const int factBits; 
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other);
        Fixed(const int integer);
        Fixed(const float float_p);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};
    
std::ostream& operator<<(std::ostream &o, const Fixed &ex); // why it works here


#endif



