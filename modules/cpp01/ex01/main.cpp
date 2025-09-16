#include "Zombie.hpp"

int main()
{
	Zombie* z = zombieHorde(1, 0);
	// Zombie* z = zombieHorde(1, "");
	// Zombie* z = zombieHorde(-1, "zizo");
	delete [] z; // the destructor is called only after you delete the pointer
}
