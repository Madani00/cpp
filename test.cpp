#include <iostream>

bool repeatedSubstringPattern(std::string s) {

        std::string newstring = s;
        if (s.size() % 2 != 0)
            return false;
    
        int half = s.size() / 2;
    

        int i;
        for (i = 0; i < 9; i++) {
            
            char last = s.back(); 
            s.pop_back();
            s = last + s;
            if (s == newstring)
                return true;
        }
        return false;
}
// "abac"        false , mine: true
int main() {
    int half = 15 / 2;
    std::cout << half << std::endl;

    std::cout << repeatedSubstringPattern("babbabbabbabbab") << '\n';  // baba      // abab
}