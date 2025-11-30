#include <iostream>
// #include <stdexcept>
using namespace std;
#include <memory>



struct B
{
    B() { 
        cout << "Constructor - B" << endl; 

        // unique_ptr<char []>ptr(new char[1024]);
        // std::auto_ptr<char> ptr(new char); // c++98 , but does not handle arrays, 

        char *p = new char[1024]; // we got leaks here
        throw runtime_error("some exception");
    }
    ~B() { // NEVER GETS CALLED AFTER EXCEPTION !!!! - memory leak 
        cout << "Destructor - B" << endl; 
        // delete[] p;
    } 
};

int main()
{
    try {
        B b;
    }
    catch (runtime_error &a) {
        cout << "Catch called:  " << a.what() << endl;
    }
}
