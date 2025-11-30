#include "Intern.hpp"

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

    AForm* (Intern::*pointer[3])(const std::string &);
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


Intern::Intern()
{
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern Copy constructor called" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern& other)
{
    std::cout << "Intern Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}
