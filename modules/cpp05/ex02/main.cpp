#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    std::cout << std::string(20, '=') << " simple creation test " << std::string(20, '=') << std::endl;
    try {
        Bureaucrat high("Boss", 10);
        Bureaucrat low("Intern", 140);
        std::cout << high << std::endl;
        std::cout << low << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::string(20, '=') << " should fail " << std::string(20, '=') << std::endl;
    try {
        Bureaucrat high("Homeless", 0);
    } catch (const GradeTooHighException& e) {
        std::cerr << "Caught exception : " << e.what() << std::endl;
    }

    std::cout << std::string(20, '=') << " should fail " << std::string(20, '=') << std::endl;
    try {
        Bureaucrat boss("Boss", 2);
        std::cout << boss << std::endl;
        boss.incrementGrade();
        std::cout << boss << std::endl;
        boss.incrementGrade();
    } catch (const GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

     
    std::cout << std::string(20, '=') << " execute test " << std::string(20, '=') << std::endl;
    ShrubberyCreationForm human("Park");
    
    Bureaucrat signer("Sam", 100); 
    signer.signForm(human);
    std::cout << human << std::endl;
    signer.executeForm(human); // success 
    Bureaucrat fail("Failure", 138); 
    std::cout << fail << std::endl;
    fail.executeForm(human); // faitl

    std::cout << std::string(20, '=') << " assignment operator " << std::string(20, '=') << std::endl;
    ShrubberyCreationForm robot("home");
    Bureaucrat chif("chif", 1);
    chif.signForm(robot);
    std::cout << robot << std::endl;
    ShrubberyCreationForm madani;
    std::cout << madani << std::endl;
    madani = robot;
    std::cout << madani << std::endl;
   
    std::cout << std::string(20, '=') << " sign form test " << std::string(20, '=') << std::endl;
    PresidentialPardonForm pet("Pet"); 
    Bureaucrat lowSigner("Bob", 29);
    Bureaucrat goodSigner("Alice", 25);
    lowSigner.signForm(pet);  // fails
    goodSigner.signForm(pet); // success
    std::cout << pet << std::endl;

    
    return 0;
}
