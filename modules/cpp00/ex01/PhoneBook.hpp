#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
		int count;
		int index;
    public:
        void add();
        void search();
		void printTable();
		PhoneBook();
        ~PhoneBook();
};

int  my_getline(std::string &str);


#endif
