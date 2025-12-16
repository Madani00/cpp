#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {

    
    try {
        std::vector<int> con = {1, 12, 1337, 80};
        vector<itr>::iterator itr;
        itr = easyfind(con, 1337);
        std::cout << "nice nadi nice nadi nice" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "caught exception: " << e.what() << std::endl;
    }

}