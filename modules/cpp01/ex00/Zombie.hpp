#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void announce( void );
		Zombie(/* args */);
		~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
}

#endif
