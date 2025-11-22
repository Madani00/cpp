#include "AForm.hpp"

AForm::AForm() 
    : name("Mr default"), isSigned(false), gradeSign(0), gradeExe(0)
{
    std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int gradeSign, const int gradeExe) 
    : name(name), isSigned(false), gradeSign(gradeSign), gradeExe(gradeExe)
{
    if (gradeSign < 1 || gradeExe < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExe > 150)
        throw GradeTooLowException();
    std::cout << "AForm constructor called" << std::endl;
}


AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const AForm& other) 
    : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExe(other.gradeExe)
{
    std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& other)
{
    std::cout << "AForm Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}


const std::string& AForm::getName() const {
    return this->name;
}
       
bool AForm::getIsSigned() const {
    return this->isSigned;
}

int AForm::getGradeToSign() const {
    return this->gradeSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeExe;
}

void AForm::beSigned(const Bureaucrat &burea) {
    if (burea.getGrade() <= this->gradeSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &outstream, const AForm &obj)
{
    outstream <<  "Name: " << obj.getName() << \
    ", signed: " << obj.getIsSigned() << \
    ", grade to sign: " << obj.getGradeToSign() << \
    ", grade to execute: " << obj.getGradeToExecute();
    return (outstream);
}

void AForm::execute(Bureaucrat const & executor) const {
    if (this->isSigned) {
        if (executor.getGrade() <= this->gradeExe) {
            this->executeAction(); 
        }
        else {
            throw GradeTooLowException();
        }
    }
    else {
        throw FormNotSignedException();
    }
}