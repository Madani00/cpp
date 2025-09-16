#include "HumanA.hpp"

void HumanA::attack( void ) const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(const std::string& name, Weapon& weapon) :
	weapon(weapon),
	name(name)
{

}

HumanA::~HumanA()
{
}
