
#include <iostream> // For std::cout, std::cerr
#include <string>     // For std::string
#include <sstream>    // For std::stringstream
#include <fstream>    // For std::ifstream, std::ofstream




int main() {
    std::stringstream ss;       // 1. Create a source stream with some data.
    ss << "Hello, this is a test.\n";
    ss << "Line 2 of the test.";
    // 2. Use rdbuf() to pipe the entire contents of 'ss'
    //    directly to the 'std::cout' stream (the console).
    std::cout << "--- Piping ss to cout: ---" << std::endl;
    std::cout << ss.rdbuf();
    return 0;
}

