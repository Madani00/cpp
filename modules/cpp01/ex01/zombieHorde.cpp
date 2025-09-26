#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	if (N <= 0) // || name.empty()
		return NULL;
	Zombie* zom = new (std::nothrow) Zombie[N]; // (std::nothrow) : to remove the error
	if (zom == NULL)
		return (NULL);
	for (int i = 0; i < N; i++)
	{
		zom[i].nameIt(name);
		zom[i].announce();
	}
	return zom;
}
