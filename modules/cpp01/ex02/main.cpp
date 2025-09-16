#include <string>
#include <iostream>

// void byptr(std::string *s)
// {
// 	*s += " to be alive";
// }

// void byConstPtr(std::string const * s) {
// 	std::cout << *s << std::endl;
// }

// void byRef(std::string & s)
// {
// 	s += " to be alive";
// }

// void byConstRef(std::string const & s) {
// 	std::cout << s << std::endl;
// }

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s; // -> alias for s (no extra memory, just another name)

	std::cout << "The memory address of the string variable: " << &s << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << s << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;


}
