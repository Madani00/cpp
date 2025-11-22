#pragma once

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        AForm* robotomy(const std::string &target);
        AForm* presidential(const std::string &target);
        AForm* shrubbery(const std::string &target);
    public:
        AForm *makeForm(const std::string& name, const std::string&form);
};


