#include "PhoneBook.hpp"


void PhoneBook::add()
{
	std::string first, last, nick, phone, dark;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, first);
	// std::cin >> first;
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, last);
	// std::cin >> last;
	std::cout << "Enter Nick Name: ";
	std::getline(std::cin, nick);
	// std::cin >> nick;
	std::cout << "Enter Phone number: ";
	std::getline(std::cin, phone);
	// std::cin >> phone;
	std::cout << "Enter Darkest secret: ";
	std::getline(std::cin, dark);
	// std::cin >> dark;
	if (first.empty() || last.empty() || nick.empty() || phone.empty() || dark.empty())
	{
		std::cout << "one of the field in empty\n";
		return ;
	}
	contacts[index].setInfo(first, last, nick, phone, dark);
	index = index % 8;
	index++;
	if (count < 8)
		count++;
}

void PhoneBook::search()
{
	std::string input;
	int nmb;

	std::cout << "Which index of the contact you want :";
	std::getline(std::cin, input);
	std::stringstream ss(input);
	ss >> nmb;
	if (ss.fail() || !(nmb >= 0 && nmb <= count))
	{
		std::cout << "Invalid number!\n";
		return ;
	}
	contacts[index].getField(index);

}
