#include "Zombie.hpp"

void Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::nameIt(std::string name) {
	this->name = name;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout  << "→ zombie "
			   << this->name
			   << " dies"
			   <<  std::endl;
}
