#include <iostream>
#include <string>
#include <cctype>
#include <vector>

#include <fstream>
#include <sstream>

#include <cstdlib>

#include <utility>


class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    // void processinput(int digit);
};