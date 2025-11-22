#pragma once

class Bureaucrat;

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSign;
        const int gradeExe;
    public:
        // Orthodox Canonical Form
        Form();
        Form(const Form& other); 
        Form& operator=(const Form& other);
        ~Form();

        Form(const std::string& name, const int gradeSign, const int gradeExe);
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &burea);
};

std::ostream& operator<<(std::ostream &outstream, const Form &obj);
