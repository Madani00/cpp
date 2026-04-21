#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <deque>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <iterator>
#include <sys/time.h>
#include <iomanip>

#include <list>


class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    template <typename Container>
    static Container merge_insertion(Container Myvector);
};
