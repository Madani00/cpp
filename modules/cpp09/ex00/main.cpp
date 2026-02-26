#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {

    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange obj;
    if (!obj.loadDatabase("data.csv")) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    obj.processInputFile(av[1]);
}
