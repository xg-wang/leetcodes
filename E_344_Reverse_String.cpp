#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        if (len < 2) return s;
        char temp_swap;
        for (int i = 0; i < len / 2; ++i) {
            s[i] ^= s[len - i - 1];
            s[len - i - 1] ^= s[i];
            s[i] ^=  s[len - i - 1];
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    std::cout << solver.reverseString("hello") << std::endl;
    return 0;
}