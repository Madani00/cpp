#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain& other)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->ideas[0] = other.ideas[0]; 
    }
    return *this;
}
