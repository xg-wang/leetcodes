// https://leetcode.com/problems/combination-sum-iv/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> combinations(target+1, 0);
        combinations[0] = 1;
        for (size_t i = 1; i <= target; i++) {
            for (size_t j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    combinations[i] += combinations[i - nums[j]];
                }
            }
        }
        return combinations[target];
    }
};

int main() {
    Solution sol;
    vector<int> in = {1,2,3};
    int target = 4;
    assert(7 == sol.combinationSum4(in, target));
    cout << sol.combinationSum4(in, target) << endl;
}
