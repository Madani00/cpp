#include <iostream>

// which one to run first is indefied

int a() { std::cout << "1"; return 1; }

int b() { std::cout << "2"; return 2; }

void foo(int a, int b) { }
int main()
{
    foo(a(), b());


}

// templates are blueprint when you do not use it ,it is not created

template <typename T>
struct A
{
    void one() {}
    void two() {}
};


int main()
{
    A<int> a;
    a.one();
}