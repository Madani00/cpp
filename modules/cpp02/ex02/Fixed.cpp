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

std::ostream& operator<<(std::ostream &outstream, const Fixed &object)
{
    outstream <<  object.toFloat();
    return (outstream);
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



// 6 comparison operators: >, <, >=, <=, ==, and !=
bool Fixed::operator >(const Fixed& object) const {
    return (this->value > object.value);
}

bool Fixed::operator <(const Fixed& object) const {
    return (this->value < object.value);
}

bool Fixed::operator >=(const Fixed& object) const {
    return (this->value >= object.value);
}

bool Fixed::operator <=(const Fixed& object) const {
    return (this->value <= object.value);
}

bool Fixed::operator ==(const Fixed& object) const {
    return (this->value == object.value);
}

bool Fixed::operator !=(const Fixed& object) const {
    return (this->value != object.value);
}

// The 4 arithmetic operators: +, -, *, and /
Fixed Fixed::operator +(const Fixed& object) {
    Fixed result;
    result.setRawBits(this->value + object.value);
    return result;
}

Fixed Fixed::operator -(const Fixed& object) {
    Fixed result;
    result.setRawBits(this->value - object.value);
    return result;
}

Fixed Fixed::operator *(const Fixed& object) {
    return Fixed(this->value * object.value);
}

Fixed Fixed::operator /(const Fixed& object) {
    return Fixed(this->value / object.value);
}

//  The 4 increment/decrement: x++, ++x, x--, --x
void Fixed::operator ++() {
    this->value += 1;
}

void Fixed::operator --() {

    this->value -= 1;
}

Fixed Fixed::operator ++(int) {
    Fixed current(*this);

    this->value += 1;
    return current;
}

Fixed Fixed::operator --(int) {
    Fixed current(*this);

    this->value -= 1;
    return current;
}

// public overloaded member functions 
Fixed& Fixed::max(Fixed& object1, Fixed& object2) {
    return (object1 > object2 ? object1 : object2);
}
