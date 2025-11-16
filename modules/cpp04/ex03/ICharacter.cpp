#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    std::cout << "ICharacter Default constructor called" << std::endl;
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter Destructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other) {
    std::cout << "ICharacter Copy constructor called" << std::endl;
    *this = other;
}

ICharacter &ICharacter::operator=(const ICharacter& other)
{
    std::cout << "ICharacter Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}