// https://leetcode.com/problems/roman-to-integer/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> roman_dic = {
            { 'I', 1    },
            { 'V', 5    },
            { 'X', 10   },
            { 'L', 50   },
            { 'C', 100  },
            { 'D', 500  },
            { 'M', 1000 }
        };

        int idx = s.size();
        int pre = 0;
        while (idx != 0) {
            idx--;
            int val = roman_dic[s[idx]];
            if (val >= pre) {
                result += val;
            } else {
                result -= val;
            }
            pre = val;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    cout << "MCMLIV = 1954" << endl;
    cout << "Output = " << solver.romanToInt("MCMLIV") << endl;
    cout << "DCXXI = 621" << endl;
    cout << "Output = " << solver.romanToInt("DCXXI") << endl;
    return 0;
}