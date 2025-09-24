#include <iostream>

// declaration syntax
// return_type (Class_Name::*pointer_name)(parameter_list) = &ClassName::member_function;

// class MyClass {
// public:
//     void greet(const std::string& name) {
//         std::cout << "Hello, " << name << "!" << std::endl;
//     }
// };

// int main() {
//     // Declare a pointer to a member function of MyClass
//     void (MyClass::*ptr_to_greet)(const std::string&) = &MyClass::greet;

//     MyClass obj; // Create an object of MyClass

//     // Call the member function through the pointer using an object
//     (obj.*ptr_to_greet)("World"); 

//     return 0;
// }

class MyClass {
public:
    int value;
    int add(int a , int b)
    {
        return (a + b);
    }
    void hello(void)
    {
        std::cout << "hello" << std::endl;
    }
};

int main() {
    
    void (MyClass::*fn)(void);

    fn = &MyClass::hello;

    MyClass test;
    (test.*fn)();
    // // or you can do
    // MyClass *test;
    // (test->*fn)();
    return (0);
}

// member function of an array
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
