#include <iostream>
#include <typeinfo>

struct Base { virtual ~Base() {} };
struct A : Base {};
struct B : Base {};

int main() {
    Base* p = new A;
    std::cout << "typeid(*p): " << typeid(*p).name() << '\n';

    // Non-portable, implementation-specific access to vptr/vtable (works on common compilers)
    void** obj = reinterpret_cast<void**>(p);
    std::cout << "vptr (from object): " << obj[0] << '\n';
    void** vtable = reinterpret_cast<void**>(obj[0]);
    std::cout << "vtable[0] (first entry): " << vtable[0] << '\n';

    delete p;
}