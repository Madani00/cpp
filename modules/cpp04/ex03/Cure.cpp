#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure Default constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure& other) { // : AMateria(other) mmm 
    std::cout << "Cure Copy constructor called" << std::endl;
    *this = other;
}

Cure &Cure::operator=(const Cure& other)
{
    std::cout << "Cure Copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// Cure::


AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}