#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
}

void Dog::makeSound() const {
    std::cout << "🐕 All bark and no bite 🐕" << std::endl;
}

std::string Dog::getType() const {
    return this->type;
}