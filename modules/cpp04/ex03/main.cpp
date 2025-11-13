#include <iostream>
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}

// int main() {

// // ------------------------ first test ----------------------------------
//     {
//         AMateria* ice = new Ice();
//         AMateria* cure = new Cure();
//         ICharacter* character = new Character("AMCHART");
    
//         character->use(0, *character); // do nothing
    
//         character->equip(ice);
//         character->equip(cure);
    
//         character->use(0, *character);
//         character->use(1, *character);
//         character->use(2, *character); // do nothing
    
//         character->unequip(0);
//         character->unequip(5); // do nothing
//         character->use(0, *character); // do nothing
//         character->use(1, *character);
        
//         ice->use(*character);
//         character->unequip(1); 
                
//         // everything is empty now lets fill them again inventory[4]
//         character->equip(new Ice());
//         character->equip(new Cure());
//         character->equip(ice);
//         character->equip(cure);
    
//         // does nothing
//         character->equip(NULL); 
//         character->equip(cure->clone()); //  delete cure->clone() inside ,if inventory is full
//         character->equip(cure->clone()); //  delete cure->clone() inside ,if inventory is full
        
//         character->use(0, *character);
//         character->use(1, *character);
//         character->use(2, *character);
//         character->use(3, *character);
        
//         character->unequip(0);
//         character->unequip(1);
//         character->unequip(2);
//         character->unequip(3);    
//         delete character;
//     }
//   // ------------------------ second test ----------------------------------
//     {
//         IMateriaSource* src = new MateriaSource();
//         ICharacter* character = new Character("Finn");
    
//         src->learnMateria(new Ice());
//         src->learnMateria(NULL); // do nothing
//         src->learnMateria(new Ice());
//         src->learnMateria(new Ice());
//         src->learnMateria(new Ice());
//         src->learnMateria(new Ice()); // storage[4] is full, do nothing and delete Ice()
    
//         src->createMateria("cure"); // returns NULL, storage has only Ice()
//         AMateria* srcIceClone = src->createMateria("ice");
    
//         srcIceClone->use(*character);
    
//         delete srcIceClone;
//         delete character;
//         delete src;
//     }

//   return 0;
// }
