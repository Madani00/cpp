#include <iostream>

using namespace std;


class Bird {
public:
  virtual void talk() const {
    cout << "tweet" << endl;
  }
};

class Chicken : public Bird {
public:
  void talk() { // misses const
    cout << "bawwk" << endl;
  }
};

int main() {
  Chicken chicken;
  Bird *b_ptr = &chicken;  
  b_ptr->talk(); // prints: tweet , why cause the function does not have same signature, above it has const
}