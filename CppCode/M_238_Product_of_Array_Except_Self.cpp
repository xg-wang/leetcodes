// https://leetcode.com/problems/product-of-array-except-self/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len, 1);
        if (len < 2) {
            result = nums;
            return result;
        }

        int base = 1;
        for (int i = 1; i < len; ++i) {
            base *= nums[i - 1];
            result[i] = base;
        }
        base = 1;
        for (int i = len - 1; i > 0; --i) {
            base *= nums[i];
            result[i - 1] *= base;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    vector<int> input = {0, 0};
    vector<int> res = solver.productExceptSelf(input);
    for (auto e: res) {
        cout << e << endl;
    }
    return 0;
}