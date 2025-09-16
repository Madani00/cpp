
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>


int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();

		// club.setType("wah way");
		// bob.attack();
	}
	{
		//Weapon club = Weapon("crude spiked club");
		// Weapon club = NULL;
		HumanB jim("Jim");
		//jim.setWeapon(club);
		jim.attack();
		Weapon club = Weapon("crude spiked club");
		club.setType("hi hi hi ");
		jim.setWeapon(club);

		jim.attack();
	}
	return 0;
}
