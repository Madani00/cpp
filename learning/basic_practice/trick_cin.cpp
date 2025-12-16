#include <iostream>
#include <inttypes.h>

int main()
{
    int x = 10;
    char y;
    std::cout << "enter a number : " << std::endl; // input 11
    std::cin >> y; // takes 1
    // y = 11

    x = x * y;

    std::cout << "output : " << x << std::endl;

}