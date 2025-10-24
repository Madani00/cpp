#include <iostream>
#include <vector>
#include <bits/stdc++.h>

// tests
// ./exe filename '' hi          (test newline)
// s1="abc", s2="" → remove occurrences
// s1 equals s2
// input "aaaa", s1="aa", s2="b" → expect "bb" (Overlapping)
// s1 empty

// first logic
// std::string replace_content(std::string &file_contents, std::string& s1, std::string& s2) {

// 	std::string result = "";
// 	size_t pos = 0, found;
// 	while ((found = file_contents.find(s1, pos)) != std::string::npos) { 
// 			result.append(file_contents, pos, found - pos);
// 			result += s2;
// 			pos = found + s1.length(); // .length() and .size() are the same
// 	}
// 	result.append(file_contents, pos, file_contents.length() - pos);
// 	return result;
// }

std::string replace_content(std::string file_contents, std::string& s1, std::string& s2) {

	// just added it cause i want the logic works under works without it
	if (s1 == s2) {
		return file_contents;
	}
	size_t pos = 0, found;
	while ((found = file_contents.find(s1, pos)) != std::string::npos) { // Various member functions of the String class return the default value of std::string::npos if a valid position or index for a substring is not found in the string.
		file_contents.erase(found, s1.size());
		file_contents.insert(found, s2.c_str());
		pos = found + s2.length();
		std::cerr << pos << std::endl;
	}
	return file_contents;
}

int main(int ac, char **av)
{
	if (ac == 4) {
		std::string s1 = av[2], s2 = av[3], filename = av[1];

		// if (s1.empty()) {
		// 	std::cerr << "replacing an empty string would be undefined" << std::endl;
		// 	return 1;
		// }
		std::ifstream infile(filename.c_str()); // .data() // not guaranteed to be null-terminated
		if (!infile.is_open()) { // or (!infile) same
			std::cerr << "Error: cannot open the file" << std::endl;
			return 1;
		}
		// std::string content;
		// if (!getline(infile, content))
        // 	std::cerr << "Error: Failed to read data" << std::endl;
		// std::cout << content;

		std::string file_contents;
		std::stringstream buffer;

		// file_contents.assign((std::istreambuf_iterator<char>(infile)),
		// 					  std::istreambuf_iterator<char>());

		buffer << infile.rdbuf();
		file_contents = buffer.str();

		infile.close();

		std::string result;
		result = replace_content(file_contents, s1, s2);


		std::string outf = filename + ".replace";
		std::ofstream outfile(outf.c_str());
		outfile << result;

	} else {
		std::cerr << "Error: arguments are missing" << std::endl;
	}
	return 0;
}


