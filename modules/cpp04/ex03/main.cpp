#include <iostream>
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

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
//         character->equip(cure->clone()); //  delete cure->clone inside ,if inventory is full
//         character->equip(cure->clone()); //  delete cure->clone inside ,if inventory is full
        
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
//         src->learnMateria(new Ice()); // storage[4] is full, do nothing and delete ice
    
//         src->createMateria("cure"); // returns null storage has only ice
//         AMateria* srcIceClone = src->createMateria("ice");
    
//         srcIceClone->use(*character);
    
//         delete srcIceClone;
//         delete character;
//         delete src;
//     }

//     // // --------- test deep copy in Character class -------------
//     // Character ha("madani");
//     // std::cout << ha.getName() << '\n';

//     // ha.equip(new Ice());  
//     // ha.equip(new Cure()); 

//     // Character kk(ha); // copy constructor
//     // std::cout << kk.getName() << '\n';
    
//     // kk.use(0, kk);
//     // kk.use(1, kk);
//     // kk.use(2, kk);
//     // kk.use(3, kk);

//   return 0;
// }

// // int main() {
// //   Character character("name");

// //   AMateria* ice = new Ice();

// //   character.equip(new Cure());
// //   character.equip(new Cure());
// //   character.equip(new Cure());
// //   character.equip(ice); // inventory[4] = [ad11, add22, add33, add44]
  
// //   character.unequip(0); // container[500] = [ad11, , ...]
  
// //   character.equip(ice); // inventory[4] = [add44, add22, add33, add44]




// }

// int main()
// {
//     // std::cout << std::string(50, '-') << std::endl;
//     // {
//     //     MateriaSource a;

//     //     for (int i = 0; i < 4; i++)
//     //     {
//     //         if (i % 2 == 0)
//     //             a.learnMateria(new Ice());
//     //         else
//     //             a.learnMateria(new Cure());
//     //     }

//     //     a.learnMateria(0);
//     //     {
//     //         MateriaSource b = a;
//     //     }
//     //     {
//     //         MateriaSource b;
//     //         b = a;
//     //     }
//     //     std::cout << a.createMateria("ice")->getType() << std::endl;
//     // }
//     std::cout << std::string(50, '-') << std::endl;
//     {
//         Character jack("jack");
//         Character bob("bob");
//         AMateria * mm = new Cure();

//         for (int i = 0; i < 6; i++)
//         {
//             if (i % 2 == 0)
//                 jack.equip(new Ice());
//             else
//                 jack.equip(new Cure());
//         }
//         jack.unequip(1);
//         jack.equip(new Ice());
//         jack.equip(mm);
//         jack.equip(0);

//         for (int i = -1; i < 6; i++)
//         {
//             jack.use(i, bob);
//         }

//         std::cout << std::string(50, '-') << std::endl;

//         jack.unequip(0);
//         jack.use(0, bob);
//         jack.equip(new Ice());
//         jack.use(0, bob);
//         jack.unequip(0);

//         std::cout << std::string(50, '-') << std::endl;
//         {
//             Character jack_copy("jack_copy");
//             Character jack1 = jack;

//             jack_copy = jack;
//             jack_copy.use(0, bob);
//         }
//         delete mm;
//     }
//     return 0;
// }
