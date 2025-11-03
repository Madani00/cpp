#include <iostream>

class Base {
public:
    void baseMethod() {
        std::cout << "hello there \n";
    }
};

class Derived1 : virtual public Base {
    // Inherits baseMethod from Base
};

class Derived2 : virtual public Base {
    // Inherits baseMethod from Base
};

class SubDerived : public Derived1, public Derived2 {
    // Attempts to inherit baseMethod from both Derived1 and Derived2
    // This may cause ambiguity because baseMethod exists in two places in the hierarchy.
};

int main() 
{
    SubDerived ob;
    ob.baseMethod(); // member found by ambiguous name lookup, to fix it add virtual

}