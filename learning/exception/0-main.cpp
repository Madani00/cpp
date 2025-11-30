#include <iostream>

void C() { throw std::runtime_error("fail"); } // C throws

void B() { C(); }  // B destroyed

void A() { B(); }  // A destroyed

// C throws
// stack unwinds → B destroyed → A destroyed → main catches

int main() {
    try {
        A();
    }
    catch (std::exception& e) { 
        std::cout << e.what();
    }
}
