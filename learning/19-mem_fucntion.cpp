#include <iostream>

// declaration syntax
// return_type (Class_Name::*pointer_name)(parameter_list);
class MyClass {
public:
    void greet(const std::string& name) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
};

int main() {
    // Declare a pointer to a member function of MyClass
    void (MyClass::*ptr_to_greet)(const std::string&) = &MyClass::greet;

    MyClass obj; // Create an object of MyClass

    // Call the member function through the pointer using an object
    (obj.*ptr_to_greet)("World"); 

    return 0;
}