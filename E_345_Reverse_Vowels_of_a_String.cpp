#include "lc_header.h"

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string::iterator pl = s.begin(), pr = s.end() - 1;
        char t;
        while (pl < pr) {
            while (!is_vowel(*pl) && pl != pr) {
                pl++;
            }
            while (!is_vowel(*pr) && pr != pl) {
                pr--;
            }
            if (*pl != *pr) {
                t = *pl;
                *pl = *pr;
                *pr = t;
            }
            pl++;
            pr--;
        }
        return s;
    }
private:
    bool is_vowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << "Given s = leetcode, return leotcede."
         << endl
         << sol.reverseVowels("leetcode") << endl;
    return 0;
}