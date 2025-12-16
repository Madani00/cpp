#include <iostream>

template<typename T>
struct A {
    void f() { 
        T x; 
        x.hello();
    }
};

int main() {
    A<int> a;
    a.f();
}