#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // pure virtual
    void move() { cout << "Shape moved!\n"; }  // normal function
};

class Circle : public Shape {
public:
    // void draw() { cout << "Drawing a circle\n"; }
    void hihi() { cout << "Drawing a circle\n"; }
};

int main() {
    // Circle c; //  circle in this case is abstract class
    
    c.draw();  // "Drawing a circle"
    c.move();  // "Shape moved!"
}