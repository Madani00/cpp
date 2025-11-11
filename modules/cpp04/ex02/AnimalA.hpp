#ifndef ANIMALA_HPP
#define ANIMALA_HPP

#include <iostream>

class AnimalA
{
    protected:
        std::string type;
    public:
        // Orthodox Canonical Form
        AnimalA();
        AnimalA(const AnimalA& other); 
        AnimalA& operator=(const AnimalA& other);
        virtual ~AnimalA();

        virtual void makeSound() const = 0;
        std::string getType() const;
};


#endif