#include <iostream>

using namespace std;

int main()
{
    union
    {
        float y;
        int a;
    } data;
    
    data.y = 4;
    cout << data.y << endl;
    cout << data.a << endl; // display the absolute value of that float
    
}
