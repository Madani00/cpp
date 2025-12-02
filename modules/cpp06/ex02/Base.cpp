#include "Base.hpp"


// Check the code. Did the student use the dynamic_cast to identify the real
// type?
// void identify(Base* p) should check if the cast return is NULL.
// void identify(Base& p) should use a try and catch block to check if the cast failed.



Base::~Base(){
    std::cout << "Base Destructor called" << std::endl;
}

