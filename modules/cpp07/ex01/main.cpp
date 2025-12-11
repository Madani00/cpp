#include "iter.hpp"


// // int main( void ) {
    
// //     const int arr[] = {0, 10, 45}; 
// //     // char arr[] = {'a', 'b', 45}; 
// //     // std::string arr[] = {"hello", "from", "heaven"}; 


// //     ::iter(arr, 3, printElement);
// //     return 0;
// // }

// #include "iter.hpp"
// #include <iostream>
// // #include <string>

// // Function that modifies elements (non-const reference)
// template <typename T>
// void incrementElement(T &elem)
// {
//     elem++;
// }

// // Function that prints elements (const reference)
// template <typename T>
// void  printElement(const T &elem)
// {
//     std::cout << elem << " ";
//     return 0;
// }

// // Function that prints elements (non-const for testing)
// template <typename T>
// void printElementNonConst(T &elem)
// {
//     std::cout << elem << " ";
// }

// // Function for strings
// void printString(const std::string &str)
// {
//     std::cout << "String: " << str << std::endl;
// }


// int main(void)
// {
//     std::cout << "=== Test 1: Int array with const function ===" << std::endl;
//     int intArr[] = {1, 2, 3, 4, 5};
//     iter(intArr, 5, printElement);
//     std::cout << std::endl;

//     std::cout << "\n=== Test 2: Int array modification ===" << std::endl;
//     iter(intArr, 5, incrementElement);
//     iter(intArr, 5, printElement);
//     std::cout << std::endl;

//     std::cout << "\n=== Test 4: Char array ===" << std::endl;
//     char charArr[] = {'a', 'b', 'c', 'd'};
//     iter(charArr, 4, printElement);
//     std::cout << std::endl;

//     std::cout << "\n=== Test 4: Char array ===" << std::endl;
//     std::string arr[] = {"hello", "from", "heaven"}; 
//     iter(charArr, 4, printElement);
//     std::cout << std::endl;

//     // std::cout << "\n=== Test 5: String array (const) ===" << std::endl;
//     // std::string strArr[] = {"hello", "world", "from", "cpp"};
//     // iter(strArr, 4, printString);


//     return 0;
// }


void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

void	warning_msg(std::string msg) {
	std::cout << " ⚠️  " << GREEN << BOLD << UNDERLINE << msg << END_STYLE << std::endl;
}

void	set_int(int &i) {
	i = std::rand() % 100;
}

void	set_char(char &c) {
	c = std::rand() % 26 + 65;
}

int	main(void) {
	int		*ints = new int[20];
	char	*strs = new char[20];

	std::srand(time(NULL));

	help_msg("Creating an array of 20 chars and assigning random chars");
	iter(strs, 20, set_char);
	iter(strs, 20, print_array<char>);
	std::cout << std::endl;
	// help_msg("Adding one to the first 10 chars");
	// iter(strs, 10, &add_one<char>);
	// iter(strs, 20, &print_array<char>);
	// std::cout << std::endl;

	// std::cout << std::endl;
	// help_msg("Creating an array of 20 ints and assigning random ints");
	// iter(ints, 20, &set_int);
	// iter(ints, 20, &print_array<int>);
	// std::cout << std::endl;
	// help_msg("Adding one to the first 10 ints");
	// iter(ints, 10, &add_one<int>);
	// iter(ints, 20, &print_array<const int>);
	// std::cout << std::endl;

	delete[] ints;
	delete[] strs;

	return (0);
}

