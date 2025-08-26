#include "Contact.hpp"
#include "PhoneBook.hpp"


PhoneBook phonebook;
std::string input;

int main()
{
	// std::cout << "*******************************************\n";
	// std::cout << "|            PHONE BOOK PROGRAM            |\n";
	// std::cout << "*******************************************\n\n";

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);

		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Unknown command! TRY AGAIN :(\n";
	}
}
