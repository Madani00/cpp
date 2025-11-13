#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        // Orthodox Canonical Form
        WrongCat();
        WrongCat(const WrongCat& other); 
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();

        void makeSound() const;
        std::string getType() const;
};

#endif