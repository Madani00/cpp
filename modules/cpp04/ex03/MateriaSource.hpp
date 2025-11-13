#pragma once


#include "AMateria.hpp"
// #include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* storage[4];
    public:
        // Orthodox Canonical Form
        MateriaSource();
        MateriaSource(const MateriaSource& other); 
        MateriaSource& operator=(const MateriaSource& other);
        ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);

};
