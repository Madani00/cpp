#include "Form.hpp"

Form::Form() 
    : name("Mr Default"), isSigned(false), gradeSign(0), gradeExe(0)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string& name, const int gradeSign, const int gradeExe) 
    : name(name), isSigned(false), 
      gradeSign(gradeSign), gradeExe(gradeExe)
{
    if (gradeSign < 1 || gradeExe < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExe > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}


Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form& other) 
    : name(other.name), isSigned(other.isSigned), 
      gradeSign(other.gradeSign), gradeExe(other.gradeExe)
{
    std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form& other)
{
    std::cout << "Form Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}


const std::string& Form::getName() const {
    return this->name;
}
       
bool Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getGradeToSign() const {
    return this->gradeSign;
}

int Form::getGradeToExecute() const {
    return this->gradeExe;
}

void Form::beSigned(const Bureaucrat &burea) {
    if (burea.getGrade() <= this->gradeSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &outstream, const Form &obj)
{
    outstream <<  "Name: " << obj.getName() << \
    ", signed: " << obj.getIsSigned() << \
    ", grade to sign: " << obj.getGradeToSign() << \
    ", grade to execute: " << obj.getGradeToExecute();
    return (outstream);
}