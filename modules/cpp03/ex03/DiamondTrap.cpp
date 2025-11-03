#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name)
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}


void DiamondTrap::whoAmI()
{
    std::cout << "my name is: " << this->name << ", ClapTrap name: " << std::endl;
}
