#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << this->type << " Default constructor called" << std::endl;
    this->brain = new Brain();
    this->brain->ideas[0] = "dog parkes";
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain();
    *(this->brain) = *(other.brain);
}

Dog &Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->brain->ideas[0] = other.brain->ideas[0];
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "🐕 All bark and no bite 🐕" << std::endl;
}

std::string Dog::getType() const {
    return this->type;
}

void Dog::getideas() const {        
    std::cout << this->brain->ideas[0] << std::endl;
}