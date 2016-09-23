#include "lc_header.h"
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum_array.resize(nums.size() + 1);
        for (size_t i = 1; i < nums.size(); i++) {
            sum_array[i] = sum_array[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i > j || j >= sum_array.size() - 1) {
            return 0;
        }
        return sum_array[j] - sum_array[i-1];
    }

private:
    vector<int> sum_array;
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
}
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);