#include "Animal.hpp"

Animal::Animal()
    : type("Animal")
{
    std::cout << this->type << " Default constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "🔇 NO sound of Animal 🔇" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}