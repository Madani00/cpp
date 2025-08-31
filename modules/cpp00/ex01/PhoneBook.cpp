#include "PhoneBook.hpp"

// count will be initialized first cause its the first one in the class
PhoneBook::PhoneBook(): index(0) , count { 0 } // called initialization list
{
	std::cout << "*******************************************\n";
	std::cout << "|            PHONE BOOK PROGRAM            |\n";
	std::cout << "*******************************************\n\n";
	// int count = 0;
	// int index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "\n\n\nbye see you later :)\n";
}

void PhoneBook::add()
{
	std::string first, last, nick, phone, dark;

	while (first.empty())
	{
		std::cout << "Enter First Name: ";
		std::getline(std::cin, first);
		if (first.empty())
			std::cout << "the field in empty!!!\n";
	}
	while (last.empty())
	{
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, last);
		if (last.empty())
			std::cout << "the field in empty!!!\n";
	}
	while (nick.empty())
	{
		std::cout << "Enter Nick Name: ";
		std::getline(std::cin, nick);
		if (nick.empty())
			std::cout << "the field in empty!!!\n";
	}
	while (phone.empty())
	{
		std::cout << "Enter Phone number: ";
		std::getline(std::cin, phone);
		if (phone.empty())
			std::cout << "the field in empty!!!\n";
	}
	while (dark.empty())
	{
		std::cout << "Enter Darkest secret: ";
		std::getline(std::cin, dark);
		if (dark.empty())
			std::cout << "the field in empty!!!\n";
	}
	index = index % 8;
	contacts[index].setInfo(first, last, nick, phone, dark);
	index++;
	if (count < 8)
		count++;
	std::cout << "\nContact added successfully!\n" << std::endl;
}

void PhoneBook::printTable() // i left it here
{
	std::string ff;
	std::string ll;
	std::string nn;

	std::cout << "|-------------------------------------------|\n";
	std::cout << "|" << std::setw(10) << "index"
              << "|" << std::setw(10) << "first name"
              << "|" << std::setw(10) << "last name"
              << "|" << std::setw(10) << "nick name"
              << "|\n";
	std::cout << "|-------------------------------------------|\n";
	int i = 0;
	while (i < count)
	{
		std::string firstName = contacts[i].getField(0);
		std::string lastName = contacts[i].getField(1);
		std::string nickname = contacts[i].getField(2);

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
		std::cout << "|" << std::setw(10) << i
				<< "|" << std::setw(10) << ff
				<< "|" << std::setw(10) << ll
				<< "|" << std::setw(10) << nn
				<< "|\n";
		std::cout << "|-------------------------------------------|\n";
		i++;
	}
}

void PhoneBook::search()
{
	std::string input;
	int nmb;

	if (!count)
	{
		std::cout << "the phone book is empty :(\n";
		return ;
	}
	printTable();
	std::cout << "\nTo see more infos select an index : ";
	std::getline(std::cin, input);
	std::stringstream ss(input);
	ss >> nmb;
	if (ss.fail())
	{
		std::cerr << "Is not a number!\n"; // cerr for errors man
		return ;
	}
	else if (!(nmb >= 0 && nmb < count))
	{
		std::cerr << "Number is out of range!\n"; // cerr for errors man
		return ;
	}
	contacts[nmb].getSpecific(nmb);

}
