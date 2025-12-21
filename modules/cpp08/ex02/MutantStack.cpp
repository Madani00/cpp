#include "MutantStack.cpp"

MutantStack::MutantStack() : std::stack()
{
    std::cout << "MutantStack Default constructor called" << std::endl;
}

MutantStack::~MutantStack()
{
    std::cout << "MutantStack Destructor called" << std::endl;
}

MutantStack::MutantStack(const MutantStack& other) : std::stack(other){
    std::cout << "MutantStack Copy constructor called" << std::endl;
    // *this = other;
}

MutantStack &MutantStack::operator=(const MutantStack& other)
{
    std::cout << "MutantStack Copy assignment operator called" << std::endl;
    std::stack::operator=(other);
    return *this;
}