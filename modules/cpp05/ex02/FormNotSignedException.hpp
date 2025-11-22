#pragma once

#include <stdexcept>


class FormNotSignedException : public std::exception
{
public:
    const char* what() const throw() {
        return "the form is NOT signed !!";
    }
};

