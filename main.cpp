#include <iostream>




#include <iostream>
#include <string>



class Demo {
    public:
        void one()  { std::cout << "one\n"; }
        void two()  { std::cout << "two\n"; }
        void three(){ std::cout << "three\n"; }
};

int main() {
    void (Demo::*ptr[])() = { &Demo::one, &Demo::two, &Demo::three };
    
    Demo d;

    for (int i = 0; i < 3; ++i) {
        (d.*ptr[i])();    // call each method in order
    }
    return 0;
}
