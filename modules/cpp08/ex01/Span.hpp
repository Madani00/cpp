#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <ctime>
#include <list>
#include <iterator>
#include <queue>


class Span {
    private:
        unsigned int N;
        std::vector<int> array;
        
    public:
        // Orthodox Canonical Form
        Span();
        Span(const Span& other); 
        Span& operator=(const Span& other);
        ~Span();

        Span(unsigned int N);
        void addNumber(unsigned int nmb);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        void printarr() const;
        template <typename Iterator>
        void addMultiple(Iterator begin, Iterator end);

};

template <typename Iterator>
void Span::addMultiple(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        begin++;
    }

    // you can also do this
    this->array.insert(array.end(), begin, end);
}
