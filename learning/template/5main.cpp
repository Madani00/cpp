#include <iostream>

// a class to accept any data types

template <typename T>
class BOX {
    private:
        T value;
    
    public:
        BOX(T value) : value(value) {}

        T get() const { return value; }
};

int main() 
{

    BOX<std::string> hi("hello madani");
    std::cout << hi.get() << std::endl;
}