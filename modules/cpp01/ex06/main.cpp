#include "Harl.hpp"


int main(int ac, char *av[]) {

    if (ac != 2) {
        std::cout << "Number of argument are not correct" << std::endl; 
        return 1;
    }
    Harl obj;
    obj.complain(av[1]);

    return 0;
}

