#include <iostream>

// type conversion
int main()
{
    std::string foods[4] = {"couscous", "pizza", "tagine", "meal", };
    for(std::string f : foods){
        std::cout << f << '\n';
    }
}