#include "iter.hpp"

void increment(int &n) {
    n++;
}

void printConst(const int &n) {
    std::cout << n << " ";
}

void print(int &n) {
    std::cout << n << " ";
}


int main(void)
{
    std::cout << "=== Test 1: array with const function ===" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    iter(intArr, 5, printConst);
    std::cout << std::endl;
	const int constArr[] = {1, 2, 3, 4, 5};
	iter(constArr, 5, printConst);
    std::cout << std::endl;

    std::cout << "\n=== Test 2: array modification ===" << std::endl;
    iter(intArr, 5, increment);
    iter(intArr, 5, print);
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Char array ===" << std::endl;
    char charArr[] = {'a', 'b', 'c', 'd'};
    iter(charArr, 4, printElement<char>);
    std::cout << std::endl;

    std::cout << "\n=== Test 4: String array ===" << std::endl;
    std::string arr[] = {"hello", "from", "heaven"}; 
    iter(arr, 3, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "\n=== Test 5: String array (const) ===" << std::endl;
    const std::string strArr[] = {"hello", "world", "from", "cpp"};
    iter(strArr, 4, printElement<std::string>);

    return 0;
}
