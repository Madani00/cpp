#include <iostream>
#include <vector>
#include <bits/stdc++.h>


int main() {

    // Open a file
    std::ifstream file("text.txt");
	std::string s;

    // Write the string to the file

	getline(file, s);

	std::cout << s;

    return 0;
}


