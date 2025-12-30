#include <iostream>
#include<list>


// std::list does not support random access. it + 3 or lis[3]
void printlist(const std::list<int> &lis) {
    for (auto e : lis)
    {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

}

int main()
{
	std::list<int> lis;
    lis.push_back(1);
    lis.push_back(2);
    lis.push_back(3);
    lis.push_front(123);
    
    printlist(lis);

    lis.insert(end(lis), 4);
	lis.insert(begin(lis), 0);
    // lis.insert(end(lis) + 1, 4); // you can not do this

    auto it = cbegin(lis);
    it = std::next(it, 5);
    lis.insert(it, 5);

    printlist(lis);

    // std::cout << n[1] << std::endl; // 23
	// n.erase(n.begin());
}
