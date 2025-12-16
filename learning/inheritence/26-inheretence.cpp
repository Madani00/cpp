#include <iostream>

class Parent {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class PublicChild : public Parent {
    // publicVar is public
    // protectedVar is protected
    // privateVar is not accessible
};

class ProtectedChild : protected Parent {
    // publicVar is protected
    // protectedVar is protected
    // privateVar is not accessible
};

class PrivateChild : private Parent {
    // publicVar is private
    // protectedVar is private
    // privateVar is not accessible
};

int main() {
    PublicChild child1;

    ProtectedChild child22;

    PrivateChild child33;
    // child33.publicVar;
}