#include <iostream>


class Base {
    public:
    virtual void do_this() {
        std::cout << "Base fucntion\n";
    }
};


class Derived : public Base {
    public:
    void do_this() {
        std::cout << "Derived (child)\n";
    }
};




int main() {

    // Base* base = new Base();
    // if (static_cast<Derived*>(base)) // behaviour correct if you don't have virtual
    // {
    //     static_cast<Derived*>(base)->do_this();
    // }

    // // correct only when we : virtual, also base pointing to derived (cause this is where the runtime check happens)
    Base* base22 = new Derived();
    // Derived* base22 = new Base();  impossible
    if (dynamic_cast<Derived*>(base22))
    {
         dynamic_cast<Derived*>(base22)->do_this();
    }


}