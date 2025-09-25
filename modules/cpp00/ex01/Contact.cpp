#include "Contact.hpp"

void Contact::setInfo(std::string f, std::string l, std::string n, std::string p, std::string d)
{
	firstName = f;
	lastName = l;
	nickname = n;
	phoneNumber = p;
	darkestSecret = d;
}

void Contact::getSpecific()
{
	std::cout << "first name : " << firstName << "\n";
	std::cout << "last name : " << lastName << "\n";
	std::cout << "nick name : " << nickname << "\n";
	std::cout << "Phone number : " << phoneNumber << "\n";
	std::cout << "little darkest secret : " << darkestSecret << "\n";
}

std::string Contact::getField(int field)
{
	if (field == 0)
		return (firstName);
	else if (field == 1)
		return (lastName);
	else if (field == 2)
		return (nickname);
	return (NULL);
}
