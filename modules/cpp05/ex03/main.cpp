#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main()
{
    Intern stagiaire;
    AForm *form;

    form = stagiaire.makeForm("robotomy", "Bender");
    if (form)
        delete form;
    std::cout << std::string(40, '=')  << std::endl;


    form = stagiaire.makeForm("presidential", "regret");
    if (form)
        delete form;
    std::cout << std::string(40, '=')  << std::endl;
    
    form = stagiaire.makeForm("shrubbery", "gardener");
    if (form)
        delete form;
    std::cout << std::string(40, '=')  << std::endl;
    
    form = stagiaire.makeForm("unknown form", "nobody");
    if (form)
        delete form;
    std::cout << std::string(40, '=')  << std::endl;

    // Intern hi;

    return 0;
}
