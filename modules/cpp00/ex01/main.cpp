#include "Contact.hpp"
#include "PhoneBook.hpp"


int main()
{
	PhoneBook phonebook;
	std::string input;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!my_getline(input))
			return 1;
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
