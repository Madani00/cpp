#include "ScavTrap.hpp"

int main() {
    ClapTrap obj1("main_character");
    obj1.attack("enemy");
    obj1.beRepaired(5);
    obj1.attack("enemy");
    obj1.takeDamage(15);
    obj1.takeDamage(6);
    obj1.attack("enemy");
    obj1.takeDamage(2);

    ScavTrap obj2("tiger");
    obj2.attack("human");
    obj2.beRepaired(5);
    obj2.attack("human");
    obj2.guardGate();
    obj2.takeDamage(100);
    obj2.takeDamage(60);
    obj2.takeDamage(5);

    ClapTrap ob3;
    // can't do nothing
    ob3.attack("hello");
    ob3.beRepaired(10);

    
}