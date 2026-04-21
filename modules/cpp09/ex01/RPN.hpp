#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void processinput(std::string input);
};