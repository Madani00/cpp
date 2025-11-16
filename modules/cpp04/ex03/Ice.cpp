#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice Default constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice& other) {
    std::cout << "Ice Copy constructor called" << std::endl;
    *this = other;
}

Ice &Ice::operator=(const Ice& other)
{
    std::cout << "Ice Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}


AMateria* Ice::clone() const {
    return new Ice();
}


void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}