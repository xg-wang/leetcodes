// https://leetcode.com/problems/single-number-iii/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb = 0;
        for (int n: nums) {
            axorb ^= n;
        }
        // get last different bit
        axorb &= -axorb;
        vector<int> result(2, 0);
        for (int n: nums) {
            if ((n & axorb) == 0) {
                result[0] ^= n;
            } else {
                result[1] ^= n;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    vector<int> v = { 1, 2, 1, 3, 2, 5 };
    vector<int> sol = solver.singleNumber(v);
    cout << sol[0] << sol[1] << endl;
    return 0;
}