#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        // Orthodox Canonical Form
        Animal();
        Animal(const Animal& other); 
        Animal& operator=(const Animal& other);
        ~Animal(); // i guess also needs to be virtual

        virtual void makeSound() const;
        std::string getType() const;
};


#endif