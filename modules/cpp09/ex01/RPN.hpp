#include <iostream>
#include <stack>
#include <string>
#include <cctype>


#include <fstream>
#include <sstream>
#include <exception>

class RPN {
private:
    

public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void processinput(std::string input);
};