#include "Bureaucrat.hpp"

int main()
{
    // test increment & decrement
    try {
        Bureaucrat obj("hi", 150);
        std::cout << obj << std::endl;
        obj.decrementGrade();

        Bureaucrat objj("hi", 1);
        std::cout << objj << std::endl;
        objj.incrementGrade();
    }
    catch (std::exception& e) { 
        std::cout << e.what();
    }

    // test const and temporary object 
    try {
        const Bureaucrat b("Bob", 5);                        // const object
        std::cout << b << std::endl;
        std::cerr << Bureaucrat("Alice", 300) << std::endl; // temporary object
        std::cerr << Bureaucrat("Alice", -1) << std::endl;
    }
    catch(std::exception &e) {
        std::cout << e.what();
    }

    // copy & asignement constructor test 
    try {
        Bureaucrat obj("bro code", 1);
        std::cout << obj << std::endl;
        Bureaucrat hi(obj);
        std::cout << hi << std::endl;
    
        Bureaucrat objj("bro code", 14);
        std::cout << objj << std::endl;
        Bureaucrat ano;
        std::cout << ano << std::endl;
        ano = objj;  // name is const so that is why we take the default
        std::cout << ano << std::endl;

    }
    catch(std::exception &e) {
        std::cout << e.what();
    }

}