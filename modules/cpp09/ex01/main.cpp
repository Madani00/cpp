#include "RPN.hpp"

int main(int ac, char *av[]) {

    if (ac != 2) {
        std::cout << "Error: More than one argument" << std::endl;
        return 1;
    }
    RPN obj;
    obj.processinput(av[1]);

    
}