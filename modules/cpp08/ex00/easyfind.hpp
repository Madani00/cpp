#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator itr;
    
    itr = find(container.begin(), container.end(), value);
    if (itr == container.end())
        throw std::invalid_argument(" Value not found");
    else
        return itr;
}