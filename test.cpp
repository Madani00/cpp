#include <iostream>

#include <string>

class Solution {
public:
    static std::string mergeAlternately(std::string word1, std::string word2) {
            std::string result;
            int size;
            if (word1.length() > word2.length())
                size = word2.length();
            else
                size = word1.length();
            
            int i;
            for (i = 0; i < size; i++) {
                result += word1[i]; 
                result += word2[i];
            }
            
            if (word1.length() > word2.length())
                result += word1.substr(i);
            else
                result += word2.substr(i);
            
            return result;
    }
};

int main()
{
    // std::string resutl = Solution::mergeAlternately("hello", "mada");
    std::cout << Solution::mergeAlternately("mdi", "aan amchart") << std::endl;
    return 0;
}