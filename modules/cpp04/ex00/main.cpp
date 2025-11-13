#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << meta->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    
    meta->makeSound();
    dog->makeSound();
    cat->makeSound();

    delete meta;
    delete dog;
    delete cat;

    // // To ensure you understood how it works,
    // WrongAnimal* meta = new  WrongAnimal();
    // WrongAnimal* cat = new WrongCat();

    // meta->makeSound();
    // cat->makeSound();
    // delete meta;
    // delete cat;

return 0;
}
