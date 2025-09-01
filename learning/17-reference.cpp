#include <string>
#include <iostream>

void byptr(std::string *s)
{
	*s += " to be alive";
}

void byConstPtr(std::string const * s) {
	std::cout << *s << std::endl;
}

void byRef(std::string & s)
{
	s += " to be alive";
}

void byConstRef(std::string const & s) {
	std::cout << s << std::endl;
}

int main()
{
	std::string s = "life is awesome";
	std::cout << s << std::endl;

	byptr(&s);
	byConstPtr(&s);

	s = "good morning";
	std::cout << s << std::endl;

	byRef(s);
	byConstRef(s);
}
