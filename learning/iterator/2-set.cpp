#include <iostream>
#include <set>
using namespace std;

// Containers that automatically keep their elements in a sorted order
// std::set: / std::multiset: / std::map: / std::multimap

int main() {

  // initialize a set of int type
  set<int> numbers = {10, 100, 50, 70, 1, 100};

  // it removes duplicates , also sortes numbers
  cout << "Numbers are: ";
  for(int num: numbers) {
    cout << num << ", ";
  }

  return 0;
}