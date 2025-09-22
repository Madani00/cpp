

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
		int count; // how many contacts currently saved (max 8)
		int index; //
    public:
        void add();
        void search();
		void printTable();
		PhoneBook();
        ~PhoneBook();
};


#endif
