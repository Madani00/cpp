#include <iostream>

int main()
{

    std::string name = "madani";
    int age = 20;

    std::string *pname = &name;
    int *page = &age;

    std::cout << *pname << "\n";
    std::cout << *page << "\n"; 
}
