#include <iostream>


int main()
{
    std::string foods[20] = {"couscous", "pizza", "tagine", "meal", };
    
    // to fill and array of elements
    fill(foods, foods + 20, "pizza");

    for(std::string f : foods){
        std::cout << f << '\n';
    }
}