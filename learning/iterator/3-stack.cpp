#include <iostream>
#include <stack>
using namespace std;

void printCopyStack(stack<int> stk) {
    while (!stk.empty()) {
         cout << "element: " << stk.top() << endl;
         stk.pop();
    }
}

int main() {

    // stack<int> stk{1,2,3}; does not work
    stack<int> stk({1,2,3});


    stk.push(10);
    stk.push(25);
    stk.push(50);
    exit(1);
    cout << "top element: " << stk.top() << endl;
    

    printCopyStack(stk);

cout << "top element: " << stk.top() << endl;

}