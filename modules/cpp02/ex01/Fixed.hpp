#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>


class Fixed
{
    private:
        int value;
        static const int factBits; 
    public:
        // Orthodox Canonical Form
        Fixed();
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        Fixed(const int integer);
        Fixed(const float float_p);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;   

};
    
std::ostream& operator<<(std::ostream &outstream, const Fixed &object);

#endif



