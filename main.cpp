#include <iostream>

#include <iostream>
#include <string>

#include <cmath> 


class Fixed
{
private:
    int _fractionalBits;
    int _rawBits = 8;
public:
    int toFloat( void ) const;
    int toInt( void ) const ;
    Fixed(float v);
    Fixed(int v);
    ~Fixed();
};

Fixed::Fixed(float v)
{
    this->_fractionalBits = v;
}
Fixed::Fixed(int v)
{
    this->_fractionalBits = v;
}
Fixed::~Fixed()
{
}



int Fixed::toInt( void ) const {
    // int _fractionalBits = Fixed::toFloat();
    return ( _fractionalBits >> 8 );
}

int Fixed::toFloat( void ) const {
    return round(this->_fractionalBits * (1 << 8));
    // return ( (float)this->_fractionalBits / (float)(1 << 8) ); 
}

int main()
{
    Fixed a(42.42f);

    std::cout << "a is " << a.toFloat() << " as integer" << std::endl;

    (std::cout << myBook) << " and " << otherBook;
    (std::cout) << " and " << otherBook;



}
