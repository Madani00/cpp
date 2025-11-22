#include "Intern.hpp"

// The makeForm() function should use some kind of array of pointers to member
// functions to handle the creation of Forms.

AForm* Intern::robotomy(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::presidential(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::shrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string &target) 
{
    std::string array[3] = {"robotomy", "presidential", "shrubbery"};

    // AForm* (Intern::*pointer[3])(const std::string &) = {&Intern::robotomy, &Intern::presidential, &Intern::shrubbery};

    AForm* (Intern::*pointer[3])(const std::string &); // another way to do it
    pointer[0] = &Intern::robotomy;
    pointer[1] = &Intern::presidential;
    pointer[2] = &Intern::shrubbery;
    int i = 0;
    while (i < 3)
    {
        if (array[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*pointer[i])(target);
        }
        i++;
    }
    std::cout << name << " this provided form name does not exists" << std::endl;
    return NULL;
}