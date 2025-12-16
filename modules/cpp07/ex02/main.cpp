#include "Array.hpp"
#include <stdlib.h>


int main() 
{
    std::cout << std::string(20, '=') << " Basic Construction " << std::string(20, '=') << std::endl;
    Array<int> numbers(42);
    std::cout << "Size should be 5: " << numbers.size() << std::endl;
    std::cout << "default values : ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::string(20, '=') << " Access " << std::string(20, '=') << std::endl;
    numbers[1] = 10;
    numbers[5] = 20;
    std::cout << "Index 1 should be 10: " << numbers[1] << std::endl;
    std::cout << "Index 5 should be 20: " << numbers[5] << std::endl;

    std::cout << std::string(20, '=') << " Deep Copy (Copy Constructor) " << std::string(20, '=') << std::endl;
    Array<int> original(3);
    original[0] = 42;
    Array<int> copy(original);
    std::cout << "Original[0] before change: " << original[0] << std::endl;
    std::cout << "Copy[0] before change: " << copy[0] << std::endl;
    copy[0] = 1337;
    std::cout << "Copy[0] after change: " << copy[0] << std::endl;
    std::cout << "Original[0] after change: " << original[0] << std::endl;

    std::cout << std::string(20, '=') << " Exception (Out of Bounds) " << std::string(20, '=') << std::endl;
    Array<int> bounds(5);
    try {
        bounds[-10];
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::string(20, '=') << " Type (std::string) " << std::string(20, '=') << std::endl;
    Array<std::string> words(3);
    words[0] = "life";
    words[1] = " is cool";
    std::cout << words[0] << " " << words[1] << std::endl;
}