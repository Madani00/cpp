#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
	this->weapon = NULL;
	this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack( void ) const {
	if (this->weapon) {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << name << " has no weapon" << std::endl;
	}
}
