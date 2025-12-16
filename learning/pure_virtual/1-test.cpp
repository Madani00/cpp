#include <iostream>

using namespace std;


class Base {
public:
    virtual ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    int *ar = new int;  // you got a leak if do not use virtual in parent destructor;
    ~Derived() { delete ar; cout << "Derived destructor\n"; }
};


int main()
{
    Base *bb = new Derived();
    delete bb;

}