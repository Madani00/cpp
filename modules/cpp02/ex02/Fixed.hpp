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
        // Orthodox Canonical Form   ------------------
        Fixed();    //                             <--|
        Fixed(const Fixed& other); //              <--|
        Fixed& operator=(const Fixed& other); //   <--|
        ~Fixed(); //                               <--|
        //--------------------------------------------|
        Fixed(const int integer);
        Fixed(const float float_p);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator >(const Fixed& object) const;
        bool operator <(const Fixed& object) const;
        bool operator >=(const Fixed& object) const;
        bool operator <=(const Fixed& object) const;
        bool operator ==(const Fixed& object) const;
        bool operator !=(const Fixed& object) const;
        Fixed operator +(const Fixed& object);
        Fixed operator -(const Fixed& object);
        Fixed operator *(const Fixed& object);
        Fixed operator /(const Fixed& object);
        Fixed& operator ++();
        Fixed& operator --();   // prefix --x, you add int to the compiler see the differences
        Fixed operator ++(int); // postfix x++, return by value (copy)
        Fixed operator --(int);
        static Fixed& max(Fixed& object1, Fixed& object2);
        static const Fixed& max(const Fixed& object1, const Fixed& object2);
        static Fixed& min(Fixed& object1, Fixed& object2);
        static const Fixed& min(const Fixed& object1, const Fixed& object2);
};
    
std::ostream& operator<<(std::ostream &outstream, const Fixed &object); // why it works here


#endif
