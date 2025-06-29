#include <iostream>


// dynamic memory : memory that is allocated after the program is already compiled and running
// usefull when we don't know how much memory we will need

int main()
{
    int *ptr = NULL;
    
    ptr = new int; // new (int)  | new(int)     , works
    *ptr = 45;

    std::cout << "address is " << ptr << '\n';
    std::cout << "value is " << *ptr << '\n';

    delete ptr;   // always free memory

}