#pragma once

class Form;

#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        // Orthodox Canonical Form
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other); 
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat(const std::string& name, int grade);
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        //new
        void signForm(Form &form);
};

std::ostream& operator<<(std::ostream &outstream, const Bureaucrat &object);

