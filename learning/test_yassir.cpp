#include <iostream>

class Base
{
private:
    /* data */
public:
    Base();
    Base(const Base &obj);
    Base &operator=(const Base &obj);
    ~Base();
};

Base::Base()
{
    std::cout << "default constructor" << std::endl;
}

Base::Base(const Base &obj)
{
    std::cout << "copy constructor" << std::endl;
    *this = obj;
}

Base &Base::operator=(const Base &obj)
{
    std::cout << "operator copy assig" << std::endl;
    return *this;
}

Base::~Base()
{
    std::cout << "destructor" << std::endl;
}

int main()
{
    Base t1, t2;
    Base t3 = t1;  // ----> copy constructor 
    //t2 = t1;  // -----> assignment operator
}

