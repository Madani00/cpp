


#include <iostream>

class Animal {
public:
    virtual void speak() { std::cout << "Animal sound\n"; }
protected:
    int v = 10;
};

class Dog : public Animal {
public:
    void speak() { std::cout << "Woof!\n"; }
    
};

int main() {
    Animal* a = new Dog();
    a->speak(); // ✅ prints "Woof!"
    
    delete a;

}
