#ifndef DOG_HPP
#define DOG_HPP

#include "AnimalA.hpp"
#include "Brain.hpp"

class Dog : public AnimalA
{
    private:
        Brain *brain;
    public:
         // Orthodox Canonical Form
        Dog();
        Dog(const Dog& other); 
        Dog& operator=(const Dog& other);
        ~Dog();    

        void makeSound() const;
        std::string getType() const;
        void getideas() const;
};

#endif