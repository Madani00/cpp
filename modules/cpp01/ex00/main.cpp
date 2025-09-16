#include "Zombie.hpp"

int main()
{
	randomChump("madani");

	Zombie* z = newZombie("zik33");
	z->announce();
	delete z; // the destructor is called only after you delete the pointer
}
