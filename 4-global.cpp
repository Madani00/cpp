#include <iostream>


int value = 5;

int main()
{
    int value = 2;

    std::cout << value << "\n"; // 2
    // works just find even with spaces
    std :: cout << ::value << "\n"; // 5
}