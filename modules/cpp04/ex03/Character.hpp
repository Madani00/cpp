#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

#define MAX_CONTAINER 500

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        AMateria* container[MAX_CONTAINER];
        static int index;
    public:
        // Orthodox Canonical Form
        Character();
        Character(const Character& other); 
        Character& operator=(const Character& other);
        ~Character();

        Character(std::string name);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};
