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
    std::cout << "Copy assignment constructor called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    this->getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits( int const raw ) {
    this->value = raw;
}