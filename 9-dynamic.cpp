#include <iostream>


// dynamic memory : memory that is allocated after the program is already compiled and running
// usefull when we don't know how much memory we will need

// int main()
// {
//     int *ptr = NULL;
    
//     ptr = new int; // new (int)  | new(int)     , works
//     *ptr = 45;

//     std::cout << "address is " << ptr << '\n';
//     std::cout << "value is " << *ptr << '\n';

//     delete ptr;   // always free memory

// }

int main()
{
    char *ptr = NULL;
    int size;

    std::cout << "enter the size to allocate: " ;

    std::cin >> size;

    ptr = new char[size];

    for (size_t i = 0; i < size; i++)
    {
        std::cout << "enter the grades:  " ;
        std::cin >> ptr[i];
    }
    
    for (size_t i = 0; i < size; i++)
    {
        std::cout << ptr[i] << " ";
    }

    delete[] ptr;   // always free memory

}