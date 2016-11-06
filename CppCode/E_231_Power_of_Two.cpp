// https://leetcode.com/problems/power-of-two/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (!(n & 1)) {
            n >>= 1;
        }
        return n == 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    cout << solver.isPowerOfTwo(2) << endl;
    return 0;
}