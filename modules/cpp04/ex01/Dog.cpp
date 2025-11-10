#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << this->type << " Default constructor called" << std::endl;
    this->brain = new Brain();
    for (size_t i = 0; i < 100; i++)
    {
        this->brain->ideas[i] = "dog parkes";
    }
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain();
    *(this) = other;
}

Dog &Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        for (size_t i = 0; i < 100; i++)
        {
            this->brain->ideas[i] = other.brain->ideas[i];
        }
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "🐕 All bark and no bite 🐕" << std::endl;
}

std::string Dog::getType() const {
    return this->type;
}

void Dog::getideas() const {           // delete it later 
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << this->brain->ideas[i] << std::endl;
    }
}