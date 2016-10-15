// https://leetcode.com/problems/contains-duplicate/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
            if (hash_set.insert(*it).second == true) {
                return true;
            }
        }
        return false;
    }

    bool containsDuplicate2(vector<int>& nums) {
        if ((nums.size() == 0) || (nums.size() == 1)) return false;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return true;;
        }
        return false;
    }
};
