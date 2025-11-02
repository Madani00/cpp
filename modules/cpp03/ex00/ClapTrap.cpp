#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : hit_points(0), energy_points(0), attack_damage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : hit_points(10), energy_points(10), attack_damage(0) // make sure to be 10
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->name = name;
}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    return *this;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points > 0 && this->energy_points > 0) {
        this->energy_points--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " \
    << this->attack_damage << " points of damage!" << std::endl;
    }
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points > 0 && this->energy_points > 0)
    {
        if (amount <= this->hit_points)
            this->hit_points -= amount;
        else
            return ;
        std::cout << "ClapTrap " << this->name << " take damage, the health now is " \
        << this->hit_points  << std::endl;
    }

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points > 0 && this->energy_points > 0) {
        this->hit_points += amount; // // the health 🔋
        this->energy_points--; 
        std::cout << "ClapTrap " << this->name << " repairs itself, hit points: " \
    << this->hit_points << " , energy points: " << this->energy_points << std::endl;
    }
}