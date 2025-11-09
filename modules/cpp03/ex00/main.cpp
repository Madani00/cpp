#include "ClapTrap.hpp"

int main() {
    ClapTrap obj1("ME");

    obj1.attack("enemy");
    obj1.beRepaired(5);
    obj1.attack("enemy");
    obj1.takeDamage(15); // skip
    obj1.takeDamage(6);
    obj1.attack("enemy");
    obj1.takeDamage(4);
    ClapTrap ob3;
    ob3.attack("hello");
    ob3.beRepaired(10);
}