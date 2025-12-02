#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void) {

    srand(time(0));
    int random = (rand() % 3) + 1;
    Base* base;

    if (random == 1) {
        base = new A();
        std::cout << "generating object: A" << std::endl;
    }
    else if (random == 2) {
        base = new B();
        std::cout << "generating object: B" << std::endl;
    }
    else {
        base = new C();
        std::cout << "generating object: C" << std::endl;
    }
    return base;
}

void identify(Base* p) {

    if (dynamic_cast<A*>(p))
        std::cout << "type of the object pointed to by p: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "type of the object pointed to by p: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "type of the object pointed to by p: C" << std::endl;
    else
		std::cout << "UNKNOWN !!" << std::endl;
}

void identify(Base& p) {
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "type of the object pointed to by p: A" << std::endl;
        return ;
    }
    catch(const std::exception& e) { }

    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "type of the object pointed to by p: B" << std::endl;
        return ;
    }
    catch(const std::exception& e) { }

    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "type of the object pointed to by p: C" << std::endl;
        return ;
    }
    catch(const std::exception& e) { }

    std::cout << "UNKNOWN !!" << std::endl;
}


int main() {
    Base *base = generate();

    std::cout << std::string(40, '=')  << std::endl;
    identify(base);

    std::cout << std::string(40, '=')  << std::endl;
    identify(*base);

    std::cout << std::string(40, '=')  << std::endl;
    identify(NULL);

    std::cout << std::string(40, '=')  << std::endl;

    // Base d;
    // identify(d);

    A a;
    identify(a);

    delete base;
}