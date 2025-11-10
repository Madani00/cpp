#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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

return 0;
}
