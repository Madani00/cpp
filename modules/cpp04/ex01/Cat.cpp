#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << this->type << " Default constructor called" << std::endl;
    this->brain = new Brain();
    this->brain->ideas[0] = "cat hungry";
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << this->type << " Destructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat Copy constructor called" << std::endl;
    this->brain = new Brain();
    // *(this->brain) = *(other.brain); // this line calles the Brain Copy assignment 
    // this->brain = other.brain; // this line cause , core dumped, invalid free
    *(this) = (other); // works, calls: Cat Copy assignment
}

Cat &Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->brain->ideas[0] = other.brain->ideas[0];
    }
    return *this;
}

void Cat::getideas() const {       
    std::cout << this->brain->ideas[0] << std::endl;
}

void Cat::makeSound() const {
    std::cout << "🐈 The Silent Meow is a special sign 🐈" << std::endl;
}

std::string Cat::getType() const {
    return this->type;
}