#pragma once


#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

// Optional: A mechanism to track "dropped" Materia to prevent memory leaks 
// (e.g., a simple array or list of AMateria* that need to be deleted later).
class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        AMateria* container[4];
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
