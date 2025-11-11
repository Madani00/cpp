#include "Cat.hpp"
#include "Dog.hpp"


int main() {
    //  COMPILE ERROR
    // AnimalA animal;                          
    // AnimalA* ptr_to_abstract = new AnimalA();
    

    // Polymorphism Check
    // AnimalA *animals[4];

    // for (size_t i = 0; i < 4; i++)
    // {
    //     if (i < 2)
    //         animals[i] = new Dog();
    //     else
    //         animals[i] = new Cat();
    // }
    // std::cout << "\n--- Making sounds ---\n";
    // for (int i = 0; i < 4; ++i)
    //     animals[i]->makeSound();
    
    // std::cout << "\n--- Deleting animals ---\n";
    // for (size_t i = 0; i < 4; i++)
    // {
    //     delete animals[i];
    // }

    // Deep copy verification
    // Dog dog1;
    // Dog dog2 = dog1; 
    // Dog dog3;
    // dog3 = dog1;

    // double free test
    // Dog* dog = new Dog();
    // Dog* copy = new Dog(*dog);
    // delete dog;
    // delete copy;

    Cat cat1;
    // cat1.getideas();
    // cat1.setideas("haaaaaaaaaaa weaaardo");
    Cat cat2 = cat1; 
    // Cat cat2;
    // cat2 = cat1; 
    // cat2.getideas();
    // Cat dog3;
    // dog3 = dog1;

    return 0;
}