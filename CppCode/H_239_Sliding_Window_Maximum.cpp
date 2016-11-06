#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k || k==0) return vector<int>();
        vector<int> res;
        deque<int> dq;
        int max_of_window = INT_MIN;
        int max_idx = 0;
        for (size_t i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() == i-k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k-1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> in = {1,3,-1,-3,5,3,6,7};
    print_array(sol.maxSlidingWindow(in, 3));
}