#include <iostream>


class Human
{
    public:  // // Access specifier
        std::string name;
        std::string job;
        int age;

        void eat(void){
            std::cout << "this person is eating\n";
        }
        void sleep(){
            std::cout << "this person is sleeping\n";
        }
};



int main()
{
    Human human1; // human1 is an object
    
    human1.name = "madani";

    std::cout << human1.name << '\n';
    human1.eat();
}

// int main()
// {
//     Human *human1 = new Human; // human1 is an object
    
//     human1->name = "madani";

//     std::cout << human1->name << '\n';
//     human1->eat();

//     delete human1;
// }