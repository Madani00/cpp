#include <iostream>


class Fixed
{
    private:
        int value;
    public:
        // Orthodox Canonical Form
        Fixed();
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other);
        ~Fixed();


};


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
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int main() {
    Fixed t1, t2;
    Fixed t3 = t1;  // ----> copy constructor 
    t2 = t1;          // -----> assignment operator
}