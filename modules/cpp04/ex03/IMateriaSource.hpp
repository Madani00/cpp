#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>


class IMateriaSource
{
    public:
        // Orthodox Canonical Form
        IMateriaSource();
        IMateriaSource(const IMateriaSource& other); 
        IMateriaSource& operator=(const IMateriaSource& other);
        virtual ~IMateriaSource();

        virtual void learnMateria(AMateria* m) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};
