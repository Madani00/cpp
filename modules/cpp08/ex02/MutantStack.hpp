#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <stack>

template <typename TYPE>
class MutantStack : public std::stack<TYPE>{

    public:
        typedef typename std::stack<TYPE>::container_type::iterator iterator;

        // Orthodox Canonical Form
        MutantStack();
        MutantStack(const MutantStack& other); 
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        iterator begin();
        iterator end();
    
};

template <typename TYPE>
MutantStack<TYPE>::MutantStack() : std::stack<TYPE>()
{
}

template <typename TYPE>
MutantStack<TYPE>::MutantStack(const MutantStack& other) : std::stack<TYPE>(other)
{
}

template <typename TYPE>
MutantStack<TYPE> &MutantStack<TYPE>::operator=(const MutantStack& other)
{
    if (this != &other)
        std::stack<TYPE>::operator=(other);
    return *this;
}

template <typename TYPE>
MutantStack<TYPE>::~MutantStack()
{
}

template <typename TYPE>
typename MutantStack<TYPE>::iterator MutantStack<TYPE>::begin() 
{ 
    return this->c.begin(); 
}

template <typename TYPE>
typename MutantStack<TYPE>::iterator MutantStack<TYPE>::end() 
{ 
    return this->c.end(); 
}