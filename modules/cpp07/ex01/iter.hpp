#pragma once
#include <iostream>
#include <stdlib.h>

// Better approach: Instead of void (*func)(TYPE &), use a template parameter for the function itself,
// like template <typename TYPE, typename FUNC> and just call func(array[i]).
// This way the compiler will deduce the correct type automatically.

template <typename TYPE>
void iter(TYPE *array, size_t const length, void (*func)(TYPE &))
{
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename TYPE>
void printElement(TYPE t)
{
    std::cout << "element : " << t << std::endl;
}

template<typename T>
void	print_array(T &val) {
	std::cout << val << " ";
};

template<typename T>
void	add_one(T &val) {
	val++;
};


# define BOLD "\e[1m"
# define THIN "\e[2m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define INVERSE "\e[7m"
# define STRIKETHROUGH "\e[9m"

# define BLACK "\e[30m"
# define RED "\e[31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"

# define TITLE BOLD INVERSE

# define END_STYLE "\e[0m"
