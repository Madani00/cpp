#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        // Orthodox Canonical Form
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other); 
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const std::string target);
        void executeAction() const; // pure virtual
};


