#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << this->type << " Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << this->type << " Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "🐈 The Silent Meow is a special sign 🐈" << std::endl;
}

std::string WrongCat::getType() const {
    return this->type;
}