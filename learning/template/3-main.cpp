#include <iostream>

template <typename TYPE, int N=5> // 5 default

class Container 
{
public:
    TYPE array[N];

    void get() {
        std::cout << "Value: " << N << std::endl;
    }
};

int main() {
    Container<int> obj;
    obj.get();

    return 0;
}