#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN &RPN::operator=(const RPN& other)
{
    if (this != &other) {
    }
    return *this;
}


//  ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
void RPN::processinput(std::string input) {

    std::stack<double> myStack;

    std::stringstream ss(input);
    std::string char_str;

    char digit_oper;


    while (ss >> char_str) {

        if (char_str.length() != 1)
            std::cout << "Not a valid digit!";

        digit_oper = char_str[0];

        if (isdigit(digit_oper))
            myStack.push(digit_oper - '0');

        else if (digit_oper == '*' || digit_oper == '+' || digit_oper == '-' || digit_oper == '/') {
            if (myStack.size() == 2) {
                int nmb1 = myStack.top(); myStack.pop();
                int nmb2 = myStack.top(); myStack.pop();
                if (digit_oper == '+')
                    myStack.push(nmb1 + nmb2);
                else if (digit_oper == '*')
                    myStack.push(nmb1 * nmb2);
                else if (digit_oper == '-')
                    myStack.push(nmb1 - nmb2);
                else if (digit_oper == '/')
                    myStack.push(nmb1 / nmb2);
            }       
        }
            

        else
            throw std::runtime_error();

    }
}