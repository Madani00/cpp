#include <iostream>

int main()
{
    int *ptr = nullptr; // or NULL
    int a = 2000;

    ptr = &a;
    if (ptr == nullptr)
        std::cout << "address is still null\n";
    else 
        std::cout << "points somewhere in memory\n";

}