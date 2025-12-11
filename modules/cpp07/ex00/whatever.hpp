#pragma once

template <typename TYPE>

void swap(TYPE &a, TYPE &b)
{
    TYPE temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename TYPE>
TYPE min(TYPE a, TYPE b)
{
    return (a < b) ? a : b;
}

template <class TYPE>
TYPE max(TYPE a, TYPE b)
{
    return (a > b) ? a : b;
}
