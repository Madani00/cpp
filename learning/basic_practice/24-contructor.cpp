#include <iostream>


class MyClass {
public:
    int a;
    // You added a constructor
    MyClass(int a) { 
        std::cout << "constructor is called automaticaly\n";
    }
    ~MyClass() {
        std::cout << "destructor is called finally by compiler\n";
    }
};

int main() {
    MyClass *obj = new MyClass(10); // This is OK
    // MyClass obj2;    // ERROR! Compiler did not create MyClass()
}