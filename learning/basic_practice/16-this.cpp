#include <iostream>

class Hi {
	int id = 0;  // this->id or (*this).id
public:
	void address() {
		std::cout << this << std::endl; // this is a pointer
	}
};



int main()
{
	Hi object1, object2, object3;
	std::cout << "address of 1: ";
	object1.address();
	std::cout <<  "address of 2: ";
	object2.address();
	std::cout <<  "address of 3: ";
	 object3.address();
}