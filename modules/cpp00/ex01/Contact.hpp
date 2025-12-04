#ifndef CONTACT_H
#define CONTACT_H


#include <iostream>
#include <iomanip>

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
        void getSpecific();
        std::string getField(int field);

};



#endif
