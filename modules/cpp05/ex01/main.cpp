#include "Bureaucrat.hpp"

int main() 
{
    std::cout << std::string(20, '=') << " valid test " << std::string(20, '=') << std::endl;
    try {
        Form f("Tax", 10, 30);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << "caught exception: " << e.what() << std::endl;
    }

    std::cout << std::string(20, '=') << " invalid test "<< std::string(20, '=') << std::endl;
    try {
        Form f("Tax", 0, 10);
    } catch (std::exception &e) {
        std::cout << "caught exception: " << e.what() << std::endl;
    }

    {
        std::cout << std::string(20, '=') << " signing successfuly " << std::string(20, '=') << std::endl;
        Bureaucrat man("Man", 30);
        Form form("Form", 40, 20);
        man.signForm(form);
        std::cout << form << std::endl;

        std::cout << std::string(20, '=') << " signing failed "<< std::string(20, '=') << std::endl;
        Form formm("Form", 5, 20);
        man.signForm(formm);
        std::cout << formm << std::endl;
    }
    {
        std::cout << std::string(20, '=') << " copy operator " << std::string(20, '=') << std::endl;
        Form original("OriginalForm", 10, 5);
        Bureaucrat man("Man", 1);
        man.signForm(original);
        Form copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;


        std::cout << std::string(20, '=') << " assignment operator " << std::string(20, '=') << std::endl;
        man.signForm(original);
        Form f2("F2", 140, 120);
    
        std::cout << "Before assignment:\n";
        std::cout << "original: " << original << std::endl;
        std::cout << "f2: " << f2 << std::endl;
    
        f2 = original;
    
        std::cout << "After assignment:\n";
        std::cout << "original: " << original << std::endl;
        std::cout << "f2: " << f2 << std::endl;
    }

    return 0;
}
