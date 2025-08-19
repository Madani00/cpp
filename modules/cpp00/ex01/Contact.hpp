#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
    private:
        std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
    public:
        void setInfo(std::string f, std::string l, std::string n, std::string p, std::string d);
        void getField(int index);
        std::string getSummary(int field);

};



#endif
