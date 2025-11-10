#ifndef CAT_HPP
#define CAT_HPP

#include "AnimalA.hpp"
#include "Brain.hpp"

class Cat : public AnimalA
{
    private:
        Brain *brain;
    public:
        // Orthodox Canonical Form
        Cat();
        Cat(const Cat& other); 
        Cat& operator=(const Cat& other);
        ~Cat();

        void makeSound() const;
        std::string getType() const;
        void getideas() const;
};

#endif