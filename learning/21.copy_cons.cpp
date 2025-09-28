#include <iostream>

#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    // Parameterized constructor
    Person(std::string n, int a) : name(n), age(a) {
        std::cout << "Parameterized constructor called for " << name << std::endl;
    }

    // Copy constructor
    Person(const Person& oth) : name(oth.name), age(oth.age) {
        std::cout << "Copy constructor called for " << name << std::endl;
    }

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Create an object using the parameterized constructor
    Person person1("Alice", 30); 
    person1.display();

    // Create a new object using the copy constructor (initialization with an existing object)
    Person person2 = person1; 
    person2.display();

    // Another way to invoke the copy constructor
    Person person3(person1);
    person3.display();

    return 0;
}