#pragma once

#include <stdexcept>

class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too low";
        }
};
