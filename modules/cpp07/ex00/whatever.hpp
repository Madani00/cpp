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
TYPE min(const TYPE &a, const TYPE &b) // do not make copy
{
    return (a < b) ? a : b;
}

template <class TYPE>
TYPE max(const TYPE &a, const TYPE &b)
{
    return (a > b) ? a : b;
}
