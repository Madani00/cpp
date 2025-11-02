#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
    if (this->hit_points > 0 && this->energy_points > 0) {
        this->energy_points--;
        std::cout << "ScavTrap " << this->name << " attacks 🎯 " << target << ", causing " \
    << this->attack_damage << " points of damage!" << std::endl;
    } 
}

// special ScavTrap ability
void ScavTrap::guardGate()
{
    std::cout << "☗ ScavTrap is now in Gate keeper mode ☗" << std::endl;
}



