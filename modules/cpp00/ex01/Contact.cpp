#include "Contact.hpp"

void Contact::setInfo(std::string f, std::string l, std::string n, std::string p, std::string d)
{
	firstName = f;
	lastName = l;
	nickname = n;
	phoneNumber = p;
	darkestSecret = d;
}

void Contact::getField(int index)
{
	std::string ff;
	std::string ll;
	std::string nn;
	std::string pp;
	std::string dd;

	if (firstName.length() > 10)
    	ff = firstName.substr(0, 9) + ".";
	else
    	ff = firstName;
	if (lastName.length() > 10)
    	ll = lastName.substr(0, 9) + ".";
	else
    	ll = lastName;
	if (nickname.length() > 10)
    	nn = nickname.substr(0, 9) + ".";
	else
    	nn = nickname;
	if (phoneNumber.length() > 10)
    	pp = phoneNumber.substr(0, 9) + ".";
	else
    	pp = phoneNumber;
	if (darkestSecret.length() > 10)
    	dd = darkestSecret.substr(0, 9) + ".";
	else
    	dd = darkestSecret;
	std::cout << "| " << index << " | " << ff << " | " <<
	ll << " | " << nn << " | " << pp << " | " << dd << std::endl;

}
