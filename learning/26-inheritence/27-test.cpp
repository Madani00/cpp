#include <iostream>


class A {
public:
    int id;
    A(int i) : id(i) { std::cout << "A constructor called. ID: " << id << std::endl; }
};

// **Crucial Step:** B virtually inherits from A
class B : virtual public A {
public:
    B(int i) : A(i), B_data(i * 10) { std::cout << "BB constructor called. ID: " << id << std::endl;  }
    int B_data;
};

// **Crucial Step:** C virtually inherits from A
class C : virtual public A {
public:
    C(int i) : A(i), C_data(i * 100) { std::cout << "CC constructor called. ID: " << id << std::endl; }
    int C_data;
};

// D inherits from B and C
class D : public B, public C {
public:
    // D is responsible for calling the A constructor!
    D(int i) : A(i), B(i), C(i) {
        // All parts of D share the *same* A::id
        std::cout << "DDDD constructor finished." << std::endl;
    }
};

void run_example_1() {
    std::cout << "**Example 1: The Diamond Fix**" << std::endl;
    D d(5);

    // Accessing the shared A::id from D
    std::cout << "A::id accessed via d: " << d.id << std::endl; 
    
    // **Tricky Check:** Both B and C refer to the same A object.
    // If you change it through one path, it changes for the other.
    d.B::id = 99; 
    std::cout << "A::id after change via B: " << d.C::id << std::endl; // Prints 99!
    std::cout << "Size of D: " << sizeof(D) << " bytes" << std::endl;
}

int main() {
    run_example_1();
}