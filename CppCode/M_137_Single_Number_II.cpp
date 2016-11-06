// https://leetcode.com/problems/single-number-ii/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int acc1 = 0, acc2 = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            acc2 = (acc2 ^ nums[i]) & (~acc1);
            acc1 = (acc1 ^ nums[i]) & (~acc2);

            cerr << "acc1: " << acc1
                 << "   \tacc2: " << acc2
                 << endl;
        }
        return acc1 | acc2;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    std::vector<int> v = { -19,-46,-19,-46,-9,-9,-19,17,17,17,-13,-13,-9,-13,-46,-28 };
    cout << solver.singleNumber(v) << endl;
    return 0;
}