#include <iostream>
class Resource
{
protected:
    std::string resource_name;
public:
    Resource(std::string resource_name);
    ~Resource();
    virtual void acquire();
};

void Resource::acquire() {
    std::cout << "yes it works madani, resources" << std::endl;
}

Resource::Resource(std::string resource_name) : resource_name(resource_name)
{
    std::cout << "resource Destructor called" << std::endl;
}

Resource::~Resource()
{
}

class Developer : virtual public Resource
{
protected:
    std::string language;
public:
    Developer(std::string name);
    ~Developer();
    void acquire();
};

void Developer::acquire() {
    std::cout << "yes it works madani, Developer Developer" << std::endl;
}

Developer::Developer(std::string name) : Resource(name)
{
}

Developer::~Developer()
{
}

class Tester : virtual public Resource
{
protected:
    std::string testing_tool;
public:
    Tester(std::string name);
    ~Tester();
    void acquire();
};

void Tester::acquire() {
    std::cout << "yes it works madani, Tester Tester" << std::endl;
}

Tester::Tester(std::string name) : Resource(name)
{
}

Tester::~Tester()
{
}

class FullStackEngineer : public Tester, public Developer
{
private:
    /* data */
public:
    FullStackEngineer(std::string name);
    ~FullStackEngineer();
};

FullStackEngineer::FullStackEngineer(std::string name) : Resource(name), Developer(name), Tester(name)
{
}

FullStackEngineer::~FullStackEngineer()
{
}



int main(){
    FullStackEngineer f("hi");
    FullStackEngineer* ptr_f = &f;
    Resource* ptr_b = ptr_f; // Will this compile?
    print_base_id(ptr_b);
}