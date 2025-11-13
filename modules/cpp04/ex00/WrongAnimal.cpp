#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : type("WrongAnimal")
{
    std::cout << this->type << " Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "🔇 NO sound of WrongAnimal 🔇" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}