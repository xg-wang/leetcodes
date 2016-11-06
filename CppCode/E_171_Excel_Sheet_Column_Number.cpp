#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int size = s.size()
        for (int i = 0, factor = 1; i < size; ++i, factor *= 26) {
            result += (s[size - i - 1] - 'A' + 1) * factor;
        }
        return result;
    }
};