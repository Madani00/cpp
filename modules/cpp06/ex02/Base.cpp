#include "Base.hpp"

// Check the code. Did the student use the dynamic_cast to identify the real
// type?
// void identify(Base* p) should check if the cast return is NULL.
// void identify(Base& p) should use a try and catch block to check if the cast failed.


Base::Base(/* args */){
    std::cout << "Base Default constructor called" << std::endl;
}


Base::~Base(){
    std::cout << "Base Destructor called" << std::endl;
}

Base * Base::generate(void) {

    srand(time(0));
    int random = (rand() % 3) + 1;
    Base* base;

    if (random == 1)
        base = new A();
    else if (random == 2)
        base = new B();
    else
        base = new C();
    return base;
}

void Base::identify(Base* p) {

    A *a = dynamic_cast<A*>(p);
    if (a)
        std::cout << "type of the object pointed to by p: A" << std::endl;
    // else 
    //     return ;
    B *b = dynamic_cast<B*>(p);
    if (b)
        std::cout << "type of the object pointed to by p: B" << std::endl;

    C *c = dynamic_cast<C*>(p);
    if (c)
        std::cout << "type of the object pointed to by p: C" << std::endl;
}

void Base::identify(Base& p) {

}
