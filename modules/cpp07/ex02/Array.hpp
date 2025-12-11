#pragma once

#include <stdexcept>
#include <iostream>

template <typename TYPE>
class Array {
    private:
        TYPE *array;
        unsigned int sizeArray;
    public:
        // Orthodox Canonical Form
        Array();
        Array(const Array& other); 
        Array& operator=(const Array& other);
        ~Array();

        Array(unsigned int n);
        TYPE& operator [](unsigned int idx);
        TYPE operator [](unsigned int idx) const ;
        unsigned int size() const;
};

// Template implementations must be in the header file

template <typename TYPE>
Array<TYPE>::Array()
{
    array = NULL;
    sizeArray = 0;
}

template <typename TYPE>
Array<TYPE>::Array(unsigned int n)
{
    array = new TYPE[n];
    sizeArray = n;

    for (unsigned int i = 0; i < n; i++) // it gives error when working with std::string
        array[i] = TYPE(); // NULL gives me an error if i do copy constructor on a default object
}

template <typename TYPE>
Array<TYPE>::~Array()
{
    delete[] array;
}

template <typename TYPE>
Array<TYPE>::Array(const Array& other) {
    if (this != &other) {
        sizeArray = other.sizeArray;
        array = new TYPE[sizeArray];
        for (unsigned int i = 0; i < sizeArray; i++)
            array[i] = other.array[i];
    }
}

template <typename TYPE>
Array<TYPE>& Array<TYPE>::operator=(const Array& other)
{
    if (this != &other) {
        delete[] array;
        sizeArray = other.sizeArray;
        array = new TYPE[sizeArray];
        for (unsigned int i = 0; i < sizeArray; i++)
            array[i] = other.array[i];
    }
    return *this;
}

template <typename TYPE>
TYPE& Array<TYPE>::operator [](unsigned int idx) {
    if (idx < 0 || idx >= sizeArray)
        throw std::out_of_range("Index out of bounds");
    return array[idx];
}

template <typename TYPE>
TYPE Array<TYPE>::operator [](unsigned int idx) const {
    if (idx < 0 || idx >= sizeArray)
        throw std::out_of_range("Index out of bounds");
    return array[idx];
}

template <typename TYPE>
unsigned int Array<TYPE>::size() const {
    return this->sizeArray;
}