// https://leetcode.com/problems/power-of-three/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n != 1 && n % 3 != 0) return false;
        switch (n % 10) {
            case 1:
            case 3:
            case 9:
                if (n / 10 == 0) {
                    return true;
                }
            case 7:
                if (n / 10 == 0) {
                    return false;
                }
                return isPowerOfThree(n / 3);
            default:
                return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    cout << solver.isPowerOfThree(729) << endl;
    return 0;
}