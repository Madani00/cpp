#include <iostream>

using namespace std;

#include <string.h>

class Dog {
private:
    int* name;
public:
    Dog(int n) {
        name = new int;
        *name = n;
    }

    // ❌ Shallow copy
    Dog(const Dog& other) {
        // deep copy: allocate a new int for this->name and copy the value
        this->name = new int(*(other.name));
        cout <<" copy is called\n";
    }

    // Copy assignment operator (rule of three)
    Dog& operator=(const Dog& other) {
        if (this != &other) {
            // delete existing resource
            delete this->name;
            // allocate and copy
            this->name = new int(*(other.name));
        }
        cout <<" asignement is called\n";
        return *this;
    }

    ~Dog() {
        cout <<"address: "<< name << "  "<< *name << " destructor called\n";
        delete name;
    }
};

int main()
{
    Dog gg(225);
    // Dog k(gg); // copy called
    
    Dog k(12);
     k = gg;     // asignement called
}