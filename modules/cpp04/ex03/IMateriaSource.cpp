#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    std::cout << "IMateriaSource Default constructor called" << std::endl;
}

IMateriaSource::~IMateriaSource()
{
    std::cout << "IMateriaSource Destructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
    std::cout << "IMateriaSource Copy constructor called" << std::endl;
    *this = other;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource& other)
{
    std::cout << "IMateriaSource Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}
