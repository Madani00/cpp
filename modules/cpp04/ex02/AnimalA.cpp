#include "AnimalA.hpp"

AnimalA::AnimalA()
    : type("AnimalA")
{
    std::cout << this->type << " Default constructor called" << std::endl;
}

AnimalA::~AnimalA()
{
    std::cout << "AnimalA Destructor called" << std::endl;
}

AnimalA::AnimalA(const AnimalA& other) {
    std::cout << "AnimalA Copy constructor called" << std::endl;
    *this = other;
}

AnimalA &AnimalA::operator=(const AnimalA& other)
{
    std::cout << "AnimalA Copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}


std::string AnimalA::getType() const {
    return this->type;
}