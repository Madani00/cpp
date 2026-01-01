#include "Span.hpp"

Span::Span() : N(0)
{
    // std::cout << "Span Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : N(N)
{
    // std::cout << "Span Default constructor called" << std::endl;
}

Span::~Span()
{
    // std::cout << "Span Destructor called" << std::endl;
}

Span::Span(const Span& other) {
    // std::cout << "Span Copy constructor called" << std::endl;
    *this = other;
}

Span &Span::operator=(const Span& other)
{
    // std::cout << "Span Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->N = other.N;
        this->array = other.array;
    }
    return *this;
}

void Span::addNumber(unsigned int nmb)
{
    if (this->array.size() < N) {
        array.push_back(nmb);
    }
    else
        throw std::out_of_range("the container is full");
}

unsigned int Span::shortestSpan() {
    if (this->array.size() < 2) {
        throw std::out_of_range("you can't measure a distance");
    }

    std::vector<int> sorted = array;
    std::sort(sorted.begin(), sorted.end());

    int min = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        if (sorted[i+1] - sorted[i] < min)
            min = sorted[i+1] - sorted[i];
    }
    return min;
}

// better if you use std::min and std::max
unsigned int Span::longestSpan() {
    
    if (this->array.size() < 2) {
        throw std::out_of_range("you can't measure a distance");
    }

    int max = array[0];
    int min = array[0];
    for (size_t i = 0; i < array.size(); i++) {

        if (array[i] > max)
            max = array[i];
        else if (array[i] < min)
            min = array[i];
    }
    return (max - min);
}

void Span::printarr() const {
    for (size_t i = 0; i < array.size(); i++) {

        std::cout << array[i] << ", ";
    }
}

