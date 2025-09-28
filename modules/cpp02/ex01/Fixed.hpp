#ifndef FIXED_H
#define FIXED_H

#include <iostream>
class Fixed
{
    private:
        double value;
        static const int factBits; 
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other);
        Fixed(const int integer);
        Fixed(const double float_p);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};



#endif


