#pragma once
#include "AForm.hpp"


#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
    private:
        static int value;
    public:
        // Orthodox Canonical Form
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other); 
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        RobotomyRequestForm(const std::string target);
        void executeAction() const; // pure virtual
       
};

