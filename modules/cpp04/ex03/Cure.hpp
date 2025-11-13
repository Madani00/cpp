#pragma once


#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria
{
    public:
        // Orthodox Canonical Form
        Cure();
        Cure(const Cure& other); 
        Cure& operator=(const Cure& other);
        ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);

};
