#include <iostream>
using namespace std;

int main()
{
    std::string str = "Hello, world!";
    // Returns std::string::npos because "abc" is not found.
    size_t position = str.find("abc");

	cout << position;
    if (position == std::string::npos)
        cout << "Substring not found";

    else
        cout << position;

    return 0;
}
