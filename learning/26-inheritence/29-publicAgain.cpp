#include <iostream>


class A {
    int age = 48;
public:
    int id = 1000;
protected:
    int acc;
    
};


class PublicAgain : private A {
public:
    A::id;         // make it public again
    // A::age; // illegal access
    A::acc;    // you can do it
    
};


int main() {
    PublicAgain obj;
    obj.id = 203;
    obj.acc; // possible

    std::cout << "A constructor called. ID: " << obj.id << std::endl;
}