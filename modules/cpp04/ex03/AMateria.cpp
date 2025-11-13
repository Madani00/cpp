#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    std::cout << "AMateria Copy constructor called" << std::endl;
    *this = other;
}

AMateria &AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria Copy assignment operator called" << std::endl;
    if (this != &other) {
    }
    return *this;
}


AMateria::AMateria(std::string const & type) {
    this->type = type;
}

std::string const& AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
     std::cout << "Defautl use function usefull: " << target.getName() <<std::endl;
}