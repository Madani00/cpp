#include <iostream>
#include <list>
#include <algorithm>

// std::for_each This algorithm applies a specific function (or "behavior") 
// to every single element in a range. It is often cleaner than a for loop

void printlist(int i) {
    std::cout << i << std::endl;
}

void incrementValue(int i) {
    std::cout << i+1 << std::endl;
}

int main()
{
	std::list<int> lis;
    lis.push_back(1);
    lis.push_back(2);
    lis.push_back(3);
    lis.push_front(150); // front

   for_each(lis.begin(), lis.end(), printlist);
    // for_each(lis.begin(), lis.end(), incrementValue);
}
