#include "RPN.hpp"

int main(int ac, char *av[]) {

    if (ac != 2) {
        std::cout << "Error: More than one argument" << std::endl;
        return 1;
    }
    try {
        RPN obj;
        obj.processinput(av[1]);

    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}