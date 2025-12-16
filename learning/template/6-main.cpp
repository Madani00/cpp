#include <iostream>


template <typename T>
void print(T x) {
    x = 23;
    std::cout << x << std::endl;
}

int main()
{
    int a = 10;
    int &ref = a;
    // print<const int&>(10); // T = int&
    print<int &>(a);       // T = int
    std::cout << a << std::endl;
    // print(ref);
}