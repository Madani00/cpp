#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath> 

using namespace std;


vector<int> plusOne(vector<int>& digits) {
    size_t last = digits.size() - 1;

    if (digits[last] != 9)
        digits[last] = digits[last] + 1;
    else {
        int digit = last;
        while (0 <= digit && digits[digit] == 9) {
            digits[digit] = 0;
            digit--;
        }
        if (digits[digit] != 9)
            digits[digit] = digits[digit] + 1;
        else if (digits[digit] == 9) {
            digits[digit] = 1;
            digits.push_back(0);
        }
    }
    return digits;
}

// --- Helper function to print the vector for testing ---
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}


int main() {
    // [5,6,2,0,0,4,6,2,4,9]
    // 5,2,2,6,5,7,1,9,0,3,8,6,8,6,5,2,1,8,7,9,8,3,8,4,7,2,5,8,9        works
    // 9
    vector<int> v1 = {9}; 
    cout << "Input 1: "; printVector(v1);
    vector<int> r1 = plusOne(v1);
    cout << " -> Output 1: "; printVector(r1);
    cout << "---" << endl;

    return 0;
}