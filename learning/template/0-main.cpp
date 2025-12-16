#include <iostream>


// Non-template overloads fucntions have priority.

template <typename T>
void print(T t)
{
    std::cout << 1 << std::endl;
}

template <>
void print(int t)
{
    std::cout << 2 << std::endl;
}


void print(int t)
{
    std::cout << 3 << std::endl;
}



int main() {
    print(0); // 3
    print<>(0); // 2
    print<int>(0); // 2
    print<double>(0.); // 1

}