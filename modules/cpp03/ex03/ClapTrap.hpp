#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;
    public:
        // Orthodox Canonical Form
        ClapTrap();
        ClapTrap(const ClapTrap& other); 
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        ClapTrap(std::string name);
        // public member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
};



#endif