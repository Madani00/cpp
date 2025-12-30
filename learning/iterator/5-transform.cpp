#include <iostream>
#include <vector>
#include <algorithm>

// It takes elements from one range, performs an operation on them, 
// and stores the result in a destination range.

int square(int n) {
    return n * n;
}

void printlist(int i) {
    std::cout << i << std::endl;
}

int main() {
    std::vector<int> input = {1, 2, 3, 4};
    std::vector<int> output(4); // Must be large enough to hold results


    transform(input.begin(), input.end(), output.begin(), square);

    for_each(output.begin(), output.end(), printlist);

}