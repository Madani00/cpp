#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::value = 0;

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm(target , 72, 45)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) 
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
    AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::executeAction() const {

    value++;
    if (value % 2 != 0) {

        std::cout << this->getName() << " has been robotomized successfully 50% of the time" << std::endl;
    }
    else {
        std::cout << "the robotomy of " << this->getName() << " failed" << std::endl;
    }
}