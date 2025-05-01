#include <iostream>

namespace first {
    int x = 5;
}
namespace second {
    int x = 10;
}
int main()
{
    using namespace second;

    std::cout << x; // 10
}