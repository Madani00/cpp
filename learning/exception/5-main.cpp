#include <iostream>
#include <exception>


// why we pass it as reference : catch (std::exception& e) 
class MyError : public std::exception {
public:
    const char* what() const throw() {
        return "My Custom Error Message!";
    }
};

int main() {
    // try {
    //     throw MyError(); // Throwing the Child type
    // } 
    // // BAD PRACTICE: Catching by VALUE
    // catch (std::exception e) { 
    //     // The 'MyError' part is sliced off. 'e' is now just a plain std::exception.
    //     std::cout << e.what() << std::endl; // Prints: "std::exception" 
    // }
    
    try {
        throw MyError();
    } 
    // GOOD PRACTICE: Catching by REFERENCE
    catch (std::exception& e) {
        // 'e' is a reference looking at the actual 'MyError' object in memory.
        std::cout << e.what() << std::endl; // Prints: "My Custom Error Message!"
    }
}