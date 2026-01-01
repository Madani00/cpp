#include <map>
#include <unordered_map> // not allowd in c++=98
#include <string>
#include <iostream>

int main() 
{
    std::map<int, std::string> schoolMap;

    // 2. Insert data (No initializer lists allowed in C++98)
    schoolMap[42] = "Born to Code";
    schoolMap[1] = "First student";
    schoolMap[21] = "Halfway there";

    // schoolMap.insert(std::make_pair(3, "hi madani"));

    std::map<int, std::string>::iterator it;
    std::cout << "--- Iterating through Map ---" << std::endl;

    for (it = schoolMap.begin(); it != schoolMap.end(); ++it) {
        // Access key with it->first and value with it->second
        std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;
    }

    // 4. Finding an element
    std::map<int, std::string>::iterator found = schoolMap.find(42);

    if (found != schoolMap.end()) {
        std::cout << "\nFound 42: " << found->second << std::endl;
    } else {
        std::cout << "\n42 not found." << std::endl;
    }

    return 0;
}