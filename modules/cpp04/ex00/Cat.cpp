#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
}

void Cat::makeSound() const {
    std::cout << "🐈 The Silent Meow is a special sign 🐈" << std::endl;
}

std::string Cat::getType() const {
    return this->type;
}