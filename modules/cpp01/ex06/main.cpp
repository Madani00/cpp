#include "Harl.hpp"

void Harl::complain( std::string level ) {
    int index = 0;

    if (level == "DEBUG") {
        index = 1;
    } 
    else if (level == "INFO") {
        index = 2;
    }
    else if (level == "WARNING") {
        index = 3;
    } 
    else if (level == "ERROR") {
        index = 4;
    } 
    switch (index) { 
        case 1:
            Harl::debug();
        case 2:
            Harl::info();
        case 3:
            Harl::warning();
        case 4:
            Harl::error();
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; 
    }
}

int main(int ac, char *av[]) {

    if (ac != 2) {
        std::cout << "Number of argument are not correct" << std::endl; 
        return 1;
    }
    Harl obj;
    obj.complain(av[1]);

    return 0;
}

