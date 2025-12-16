#pragma once

#include <algorithm>
#include <exception>
#include <iostream>

template <typename T>
void easyfind(T &container, int value)
{
    vector<T>::iterator itr;
    
    itr = find(container.begin(), container.end(), value);
    if (itr == container.end())
        throw std::invalid_argument("Value not found");
    else
        return itr;
}