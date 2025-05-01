#include <iostream>

namespace first {
    int x = 5;
}
namespace second {
    int x = 10;
}
int main()
{
    int x = 0;

    std::cout << first::x; // 5
}