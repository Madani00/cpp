#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << this->type << " Default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << this->type << " Destructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "🐈 The Silent Meow is a special sign 🐈" << std::endl;
}

std::string Cat::getType() const {
    return this->type;
}