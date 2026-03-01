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


// ./RPN "1 0  / "    (seg fault)
// ./RPN "1 +"	Insufficient operands for operator
// ./RPN "1 0 /"	Division by zero
// ./RPN "10 2 +"	Multi-digit number (tokens must be single char)
// ./RPN "1 2 3 +"	Too many numbers (extra operand)
// ./RPN ""	Empty input
// ./RPN "1 2 3"	Multiple final operands
// ./RPN "+"	Operator with no operands


void RPN::processinput(std::string input) {

    std::stack<double> myStack;
    std::stringstream ss(input);
    std::string char_str;
    char digit_oper;

    while (ss >> char_str) {

        if (char_str.length() != 1) {
            throw std::invalid_argument("Error");
        }

        digit_oper = char_str[0];

        if (isdigit(digit_oper))
            myStack.push(digit_oper - '0');

        else if (digit_oper == '*' || digit_oper == '+' || digit_oper == '-' || digit_oper == '/')
        {
            if (myStack.size() < 2)
                throw std::invalid_argument("Error");
            
            int nmb1 = myStack.top(); myStack.pop(); // 4
            int nmb2 = myStack.top(); myStack.pop(); // 2
            if (digit_oper == '+')
                myStack.push(nmb1 + nmb2);
            else if (digit_oper == '*')
                myStack.push(nmb1 * nmb2);
            else if (digit_oper == '-')
                myStack.push(nmb2 - nmb1);
            else if (digit_oper == '/') {
                if (nmb1 == 0)
                throw std::invalid_argument("Error: can't divide by 0");
                myStack.push(nmb2 / nmb1);  
            }
        
        }
        else
            throw std::invalid_argument("Error");

    }

    if (myStack.size() == 1) {
        std::cout << myStack.top() << std::endl;
    }
    else
        throw std::invalid_argument("Error");

}