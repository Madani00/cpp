#pragma once

class AMateria; // mmmmmmmmmmmmm i guess it fixes it

#include <string>
#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
    public:
        // Orthodox Canonical Form
        ICharacter();
        ICharacter(const ICharacter& other); 
        ICharacter& operator=(const ICharacter& other);
        virtual ~ICharacter();

        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;

};

