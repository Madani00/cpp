#include <iostream>
#include <string.h>
#include <fstream>

class Test
{
    private:
        int num;
    public:
        Test();
        Test(int num);
        ~Test();
        int getNum() const;
};

Test::Test()
{
}

Test::Test(int num) : num(num)
{
}
Test::~Test()
{
}

int Test::getNum() const {
    return num;
}

// General ostream operator - works for all output streams (cout, ofstream, etc.)
std::ostream& operator<<(std::ostream& out, const Test& object)
{
    return out << object.getNum();
}

int main()
{
    Test obj(12);
    std::string filename = "/";
    std::ofstream outfile(filename);
    
    if (!outfile.is_open()) {
        std::cerr << "error << " << std::perror << std::endl;
        return 1;
    }
    
    // Write to file using the operator
    outfile << obj << std::endl;
    
    // Also works with cout
    std::cout << "Object written to file: " << obj << std::endl;
    
    outfile.close();
    return 0;
}
