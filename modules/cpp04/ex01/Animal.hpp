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
        virtual ~Animal(); // if we remove virtual ,the compiler will throw us error that you are trying to delete a non virtull
        // second : it only called the destructor of the parent class animal

        virtual void makeSound() const;
        std::string getType() const;
};


#endif