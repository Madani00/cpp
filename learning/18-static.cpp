#include <iostream>

class MyClass {
public:
    int myVariable;

    void myFunction() {
        std::cout << "This is a member function." << std::endl;
    }

    static int myStaticVariable;

    static void myStaticFunction() {
        std::cout << "This is a static member function." << std::endl;
    }
};

int MyClass::myStaticVariable = 42;

int main() {
    MyClass obj;

    // Accessing non-static member variable using an object
    obj.myVariable = 10;
    std::cout << obj.myVariable << std::endl;

    // Calling non-static member function using an object
    obj.myFunction();

    // Accessing static member variable using the class name
    MyClass::myStaticVariable = 20;
    std::cout << MyClass::myStaticVariable << std::endl;

    // Calling static member function using the class name
    MyClass::myStaticFunction();

    return 0;
}