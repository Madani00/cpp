#include <iostream>

class Vector {
private:
    int x, y;
public:
    Vector() : x(0), y(0) {}
    Vector(int x, int y) : x(x), y(y) {}
    Vector(const Vector& other) : x(other.x), y(other.y) {}
    Vector& operator=(const Vector& other) {
        if (this != &other) { // object = object; also is safe to avoid if object if freed
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    ~Vector() {}
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }
    void print() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};
int main() {
    Vector a(1, 2);
    Vector b(3, 4);
    Vector c(a);


    c = a; 
    c.print();         
}



// // ----------------------------------------------------------------------------------------------------------
// class Person {
//     private:
//         std::string name;
//     public:  
//         Person() : name("") {}
//         Person(std::string n) : name(n) {}
//         Person(const Person& other) : name(other.name) {}
//         Person& operator=(const Person& other) {
//             if (this != &other) // checks object = object;
//                 name = other.name;
//             return *this;
//         }
//         ~Person() {}
//         bool operator==(const Person& oth) {
//             return (name == oth.name);
//         }
//         bool operator!=(const Person& oth) {
//             return !(*this == oth);
//         }
// };
// int main() {
//     Person p1("Alice");
//     Person p2("Alice");
//     Person p3("Bob");
//     std::cout << (p1 == p2) << std::endl; // 1 (true)
//     std::cout << (p1 != p3) << std::endl; // 1 (true)
// }
// // ----------------------------------------------------------------------------------------------------------
