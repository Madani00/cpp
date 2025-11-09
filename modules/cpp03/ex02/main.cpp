#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap obj1("main_character");

    obj1.attack("enemy");
    obj1.beRepaired(5);
    obj1.attack("enemy");
    obj1.takeDamage(100);
    obj1.takeDamage(5);
    obj1.attack("enemy");
    obj1.takeDamage(2);
    // its function
    obj1.highFivesGuys();
 
}