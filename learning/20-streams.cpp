#include <iostream>
#include <sstream>

int main()
{
    std::string s = "12";
    int n;
    
    std::stringstream stm(s);
    stm >> n;
    std::cout << n << std::endl;
}