#include "Fixed.hpp"


const int Fixed::factBits = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    this->getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream &o, const Fixed &ex)
{
    o <<  ex.toFloat();
    return (o);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return this->value;
}

void Fixed::setRawBits( int const raw ) {
    this->value = raw;
}

Fixed::Fixed(const int integer) {
    std::cout << "Int constructor called" << std::endl;
    this->value = (integer * (1 << this->factBits));   
}

Fixed::Fixed(const float float_p) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(float_p * (1 << this->factBits)); // floating --> fixed
}


float Fixed::toFloat( void ) const {
    return (float)this->value / (1 << this->factBits);
}

int Fixed::toInt( void ) const {
    return this->value / (1 << this->factBits); // roundf 
}