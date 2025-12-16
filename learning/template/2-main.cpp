#include <iostream>

template <typename T>
class Container {
public:
    T value;

    // Method 1: Valid for almost anything
    void printValue() {
        std::cout << "Value: " << value << std::endl;
    }

    // Method 2: ONLY valid if T is a pointer (like int*)
    // This is broken if T is a regular int
    void printAddress() {
        std::cout << "Address pointed to: " << *value << std::endl; 
    }
};

int main() {
    Container<int> box; 
    box.value = 42;

    // 1. This works perfectly.
    box.printValue();

    box.printAddress();
    // 2. We never called box.printAddress().
    // Therefore, the compiler NEVER generated code for printAddress().
    // If it had generated code, it would have crashed because you cannot do "*value" on an int.
    
    std::cout << "I ignored the broken method inside the class!" << std::endl;

    return 0;
}