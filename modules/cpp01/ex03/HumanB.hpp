#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		Weapon* weapon;
		std::string name;
	public:
		void attack( void ) const;
		void setWeapon(Weapon& weapon);
		HumanB(const std::string& name);
		~HumanB();
};


#endif
