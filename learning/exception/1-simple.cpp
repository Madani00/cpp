#include <iostream>



void rethrowing (int n) { // noexcept, will not throw
    try {
        if (n < 0)
        {
            throw 5;
            std::cout << "jdfdf"; // doesnt prints
        }
    }
    catch (int e) {  // e  : the exception handler.
        std::cout << e << " int exception is negative\n";
        throw; // rethrowing
    }
}

int main() {
    try {
        rethrowing(-4);
    }
    catch (int e) {  // e  : the exception handler.
        std::cout << e << " catching it again\n";
    }

    catch (char e) { std::cout << e <<  "int exception"; }
    // catch (...) { std::cout << "default exception"; }

    std::cout << "it does not print this if not match found";
}
