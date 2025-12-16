#include <iostream>

// you can use reinterpret_cast to access private values

class Target {
private:
    int private_secret_value = 42;
    int another_private_value = 10;
public:
    int get_public_value() const { return private_secret_value; }
};

struct Hacker {
    int secret_value_hack;
    int filler_value;
};

int main() {
    Target original_object;

    // 1. Get a pointer to the original object.
    Target* target_ptr = &original_object;

    // 2. THIS IS THE DANGEROUS STEP:
    //    We reinterpret the pointer to 'Target' as a pointer to 'Hacker'.
    //    The compiler assumes we know what we are doing and makes the raw cast.
    Hacker* hacker_ptr = reinterpret_cast<Hacker*>(target_ptr);

    // 3. We now access the 'private_secret_value' via the 'Hacker' struct's member.
    std::cout << "Original Public Value: " << original_object.get_public_value() << std::endl;
    std::cout << "Hacked Private Value: " << hacker_ptr->secret_value_hack << std::endl;
    std::cout << "Hacked filler Value: " << hacker_ptr->filler_value << std::endl;

    // You can even change the value:
    hacker_ptr->secret_value_hack = 999;

    std::cout << "Value after HACKING: " << original_object.get_public_value() << std::endl;

    return 0;
}


