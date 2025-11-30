#include <iostream>

int main() {

// static_cast relies on compile-time type information.
// The C++ standard explicitly defines conversions between data pointers and void*.
    int* a = new int();
    *a = 42;
    void* b = static_cast<void*>(a);
    // char b = static_cast<char>(a); // 'int *' --> 'char' not allowed
    int* c = static_cast<int*>(b);
    std::cout << *c << std::endl;


// tells the compiler: "Shut up and treat these bits as this new type."
    // int* a = new int();
    // void* b = reinterpret_cast<void*>(a);
    // int* c = reinterpret_cast<int*>(b);

}