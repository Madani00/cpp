#include "Zombie.hpp"

// The destructor is called immediately after randomChump returns (stack object).

void randomChump( std::string name ) {
	Zombie zom = Zombie(name);
	zom.announce();
}
