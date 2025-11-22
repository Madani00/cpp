#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("Default"), grade(0)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) 
    : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
    : name(other.name), grade(other.grade) 
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}


const std::string& Bureaucrat::getName() const {
    return this->name;
}
       
int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::incrementGrade() { 
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    else
        this->grade -= 1;
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    else
        this->grade += 1;
}


std::ostream& operator<<(std::ostream &outstream, const Bureaucrat &object)
{
    outstream <<  object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
    return (outstream);
}