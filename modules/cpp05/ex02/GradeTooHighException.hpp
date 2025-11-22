#pragma once

#include <stdexcept>

class GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade is too high";
    }
};