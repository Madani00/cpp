#include <iostream>

void megaphone_print(std::string str) {

    for (size_t j = 0; j < str.length(); j++)
    {
        std::cout << (char)toupper(str[j]);
    }
}


int main(int ac, char **av)
{
    if (ac <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    for (int i = 1; i < ac; i++)
    {
        megaphone_print(av[i]);
    }
    std::cout << std::endl;
}