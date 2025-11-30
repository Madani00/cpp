#include <iostream>

// templates  let you write a function or class that works with different data types.
// you don't have to  create  many functions anymore 

// template <typename T>

template <typename VA1, typename VA2>

// auto is telling the compiler to return the final output result 
auto max(VA1 x, VA2 y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << max(1, 2.1) << "\n";
}