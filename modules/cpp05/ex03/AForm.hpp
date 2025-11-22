#pragma once

class Bureaucrat;

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"



class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSign;
        const int gradeExe;
    public:
        // Orthodox Canonical AForm
        AForm();
        AForm(const AForm& other); 
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        AForm(const std::string& name, const int gradeSign, const int gradeExe);
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &burea);
        void execute(Bureaucrat const & executor) const;
    protected:
        virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream &outstream, const AForm &obj);
