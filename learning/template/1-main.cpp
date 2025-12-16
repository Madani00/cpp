#include <iostream>



template <typename T>
void buggyFunction(T value) {
    // ERROR: This assumes 'T' has a method called .fly()
    // Integers do not have a .fly() method!
    value.fly(); 
}

// // this gives error
// void buggyFunction(int value) {
//     value.fly(); 
// }


int main() {
    int myNumber = 10;
    // If you run this code as is, it COMPILES SUCCESSFULLY.
    std::cout << "I compiled fine because I ignored the template!" << std::endl;

    // buggyFunction(myNumber); 
    // As soon as you uncomment that line, the compiler MUST build the code.
    // It will realize "int" has no member "fly" and throw an error.
    
    return 0;
}