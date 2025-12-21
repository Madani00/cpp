#include "MutantStack.hpp"

void printCopyStack(std::stack<int> stk) {
    while (!stk.empty()) {
        std::cout << "element: " << stk.top() << std::endl;
        stk.pop();
    }
    std::cout << std::endl;
}

void iteratorTest() {

    MutantStack<int> m;

    m.push(5);
    m.push(10);
    m.push(15);

    MutantStack<int>::iterator it = m.begin();

    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;
    --it;
    std::cout << *it << std::endl;
    std::cout << std::endl;
}

void basicTest() {
    MutantStack<int> mstack;

    mstack.push(1);
    mstack.push(170);

    std::cout << mstack.top() << std::endl;
    mstack.pop();

    std::cout << "size of stack: "<< mstack.size() << std::endl;

    mstack.push(2);
    mstack.push(3);
    mstack.push(40);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
}

void copyTest() {
    MutantStack<int> original;

    original.push(100);
    original.push(200);

    MutantStack<int> copy(original);

    original.pop();

    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << std::endl;
}   

void listTest() {
    MutantStack<int> m;
    std::list<int> l;

    for (int i = 0; i < 5; i++)
    {
        m.push(i);
        l.push_back(i);
    }

    MutantStack<int>::iterator it1 = m.begin();
    std::list<int>::iterator it2 = l.begin();

    while (it1 != m.end() && it2 != l.end())
    {
        std::cout << *it1 << " | " << *it2 << std::endl;
        ++it1;
        ++it2;
    }
     std::cout << std::endl;
}

int main()
{
    basicTest();
    iteratorTest();
    copyTest();
    listTest();
    return 0;
}