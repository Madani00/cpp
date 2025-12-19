#include "easyfind.hpp"

void list_test();
void vector_test();
void deque_test();


int main() {
    list_test();
    vector_test();
    deque_test();
}

void list_test()
{
    std::cout << "\n--- Testing std::list ---" << std::endl;
    std::list<int> con;
    con.push_back(1);
    con.push_back(12);
    con.push_back(1337);
    con.push_back(42);
    
    std::list<int>::iterator itr;
    try {
        itr = easyfind(con, 42);
        std::cout << "Value found: " << *itr << std::endl;

        easyfind(con, 999);
    }
    catch (std::exception &e) {
        std::cout << 999 << e.what() << std::endl;
    }
}

void vector_test()
{
    std::cout << "\n--- Testing std::vector ---" << std::endl;
    std::vector<int> con;
    con.push_back(1);
    con.push_back(12);
    con.push_back(1337);
    con.push_back(42);
    
    std::vector<int>::iterator itr;
    try {
        itr = easyfind(con, 1337);
        std::cout << "Value found: " << *itr << std::endl;

        easyfind(con, 999);
    }
    catch (std::exception &e) {
        std::cout << 999 << e.what() << std::endl;
    }
}

void deque_test()
{
    std::cout << "\n--- Testing std::deque ---" << std::endl;
    std::deque<int> con;
    con.push_back(1);
    con.push_back(12);
    con.push_back(1337);
    con.push_back(42);
    
    std::deque<int>::iterator itr;
    try {
        itr = easyfind(con, 1);
        std::cout << "Value found: " << *itr << std::endl;

        easyfind(con, 999);
    }
    catch (std::exception &e) {
        std::cout << 999 << e.what() << std::endl;
    }
}