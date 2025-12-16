#include <iostream>
#include <iomanip>

int main()
{ 
    std::cout << std::fixed << std::setprecision(6); // means after . set 6 numbers
    std::cout << 7 / 5 << std::endl; // prints : 1
    std::cout << (float)7 / 5 << std::endl; // prints : 1.400000
    return (0);
}

