#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
    int i = 0;
    while (i < 4)
    {
        this->storage[i] = NULL;
        i++;
    }
    std::cout << "MateriaSource Default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    while (i < 4)
    {
        if (this->storage[i])
            delete this->storage[i];
        i++;
    }
    std::cout << "MateriaSource Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}


void MateriaSource::learnMateria(AMateria* m) {
    if (m != NULL) {
        int i = 0;
        while (i < 4)
        {
            if (this->storage[i] == NULL) {
                this->storage[i] = m;
                return;
            }
            i++;
        }
        delete m; /////////// mmm i guess 
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    int i = 0;
    while (i < 4)
    {
        if (this->storage[i] && this->storage[i]->getType() == type) {
            return this->storage[i]->clone();
        }
        i++;
    }
    return NULL;
}