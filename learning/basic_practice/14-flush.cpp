#include <iostream>
#include <unistd.h>

int main() 
{
    std::cout << "Hello";
    sleep(3); // wait 3 seconds
    std::cout << " world\n";

    // shows the hello first then world
    std::cout << "Hello" << std::endl; // or std::flush
    sleep(3);
    std::cout << " world\n";
}
