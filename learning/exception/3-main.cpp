#include <iostream>
#include <stdexcept>


void intermediateHandler() {
    std::cout << std::string(50, '-') << std::endl;
    try
    {
        throw std::runtime_error("| Disk access failed. |");
    } 
    catch (const std::runtime_error& e) {

        std::cerr << "  Caught error: " << e.what() << std::endl;
        
        // rethrows the EXACT SAME exception object.
        std::cout << "  Rethrowing the exception up the stack." << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        throw; 
    }
}

int main() {
    
    try {
        intermediateHandler();
    } catch (const std::runtime_error& e) {
        // --- Final Handling ---
        std::cerr << "THE same Error message: " << e.what() << std::endl;
    }

    std::cout << std::string(50, '-') << std::endl;
    return 0;
}