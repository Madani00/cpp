#pragma once
#include <iostream>
#include <stdlib.h>

template <typename TYPE, typename FUNC> 
void iter(TYPE *array, size_t const length, void (*func)(FUNC &))
{
    // if (!array || !func)
    //     return ;
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename TYPE>
void printElement(const TYPE &t)
{
    std::cout << "element : [" << t << "]" << std::endl;
}


