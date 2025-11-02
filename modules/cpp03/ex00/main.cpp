#include "ClapTrap.hpp"

int main() {
    ClapTrap obj1("madani");
    // ClapTrap obj2("enemy");


    obj1.attack("enemy");
    // obj1.beRepaired(5);
    obj1.beRepaired(5);
    obj1.attack("enemy");
    obj1.takeDamage(15);
    obj1.takeDamage(6);
    obj1.attack("enemy");
    obj1.takeDamage(2);

    ClapTrap ob3;
    // can't do nothing
    ob3.attack("hello");
    ob3.beRepaired(10);

    
}