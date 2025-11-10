#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    Animal *animals[10];

    for (size_t i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (size_t i = 0; i < 10; i++)
    {
        delete animals[i];
    }

    // Cat basic;
    // {
    //     Cat tmp = basic;
    // }
    // Cat basic;
    // // Cat hi = basic; // copy constructor
    // Cat hi;
    // hi = basic;
    // hi.getideas();
    // basic.getideas();

    // Dog basic;
    // {
    //     Dog tmp = basic;
    //     tmp.getideas();
    // }

return 0;
}
