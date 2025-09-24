#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug( void ) {
    std::cout << "90% is debugging" << std::endl;
}

void Harl::info( void ) {
    std::cout << "INFORTATION IF ALL YOU NEED!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "Warning the world is about to end" << std::endl;
}

void Harl::error( void ) {
    std::cout << "Error in your system" << std::endl;
}

void Harl::complain( std::string level ) {

    std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*pointer[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int i = 0;
    while (i < 4)
    {
        if (array[i] == level)
        {
            (this->*pointer[i])();
            return ;
        }
        i++;
    }
    std::cout << "Comment not found!! try again" << std::endl;
}