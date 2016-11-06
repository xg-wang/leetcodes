// https://leetcode.com/problems/contains-duplicate-ii/

#include "lc_header.h"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0 || nums.empty()) return false;
        unordered_set<int> hash;
        int nums_len = nums.size();
        for (int i = 0; i < min(k, nums_len); ++i) {
            if (hash.find(nums[i]) != hash.end()) {
                return true;
            } else {
                hash.insert(nums[i]);
            }
        }
        for (int i = k; i < nums.size(); ++i) {
            if (hash.find(nums[i]) != hash.end()) {
                return true;
            } else {
                hash.erase(nums[i - k]);
                hash.insert(nums[i]);
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> v = {1,2,3,4,5};
    cout << sol.containsNearbyDuplicate(v, 10) << endl;
    return 0;
}