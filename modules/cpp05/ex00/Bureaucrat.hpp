#pragma once

#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

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
};

std::ostream& operator<<(std::ostream &outstream, const Bureaucrat &object);

