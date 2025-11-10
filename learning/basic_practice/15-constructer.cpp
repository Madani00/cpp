#include <iostream>

// class Human
// {
//     public:
//         int age;
//         Human(): age(200){};
// };

// int main()
// {
//     Human h1;
//     std::cout << h1.age << std::endl;
// }

class Human {
    public:
        std::string name;
        int age;

        Human(std::string str, int num) { // vParameterized Constructor
            age = num;
            name = str;
            std::cout << "Constructor is automatically called!" << std::endl;
        }
};

int main() {
    Human h("madani", 70);  // Constructor is automatically called!

    std::cout << h.age << std::endl;
}
