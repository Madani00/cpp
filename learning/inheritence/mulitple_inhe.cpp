#include <iostream>

using namespace std;

class A
{
        int x;
    public:
            A() { x = 1; cout << "A"; }
};

class B : virtual public A
{
            int y;
    public:
            B() { y = 2; cout << "B"; }
};

class C : virtual public A
{
                int z;
        public:
                C() { z = 3; cout <<"C"; }
};

class D : public B, public C
{
            int t;
    public:
            D() { t = 4; cout << "D"; }
};

int main()
{
    D d; // ABCD
    return 0;
}