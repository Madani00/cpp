#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Division by zero!");

    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << result << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Caught an exception: " << e.what() << "\n";
    }
}
