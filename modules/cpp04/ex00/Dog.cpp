#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << this->type << " Default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << this->type << " Destructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "🐕 All bark and no bite 🐕" << std::endl;
}

std::string Dog::getType() const {
    return this->type;
}