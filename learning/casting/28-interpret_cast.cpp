#include <iostream>

// int main() {

// // // static_cast relies on compile-time type information.
// // // The C++ standard explicitly defines conversions between data pointers and void*.
//     int* a = new int();
//     *a = 42;
//     void* b = static_cast<void*>(a);
//     // char b = static_cast<char>(a); // 'int *' --> 'char' not allowed
//     int* c = static_cast<int*>(b);
//     std::cout << *c << std::endl;


// // // tells the compiler: "Shut up and treat these bits as this new type."
//     int* a = new int();
//     void* b = reinterpret_cast<void*>(a);
//     // char b = reinterpret_cast<char>(a); works
//     int* c = reinterpret_cast<int*>(b);

// }



// =================== static cast ==============================
class Base {};
class Derived : public Base {};


class Cat {};

int main() {
    // 1. Simple Value Conversion (Safe)
    double pi = 3.14;
    int number = static_cast<int>(pi); // Logic: Truncates decimal. number = 3.

    // 2. Pointer Conversion (The Standard Way)
    // Base* b = new Derived(); 
    // // "I know this Base pointer is actually a Derived object, trust me."
    // Derived* d = static_cast<Derived*>(b); 
    Base* base = new Base();

    Derived* b = static_cast<Derived*>(base); // always safe

}