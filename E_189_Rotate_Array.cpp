#include "lc_header.h"

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()) {
            k = k % nums.size();
        }
        self_rotate(nums.begin(), nums.end()-k);
        self_rotate(nums.end()-k, nums.end());
        self_rotate(nums.begin(), nums.end());
    }
private:
    void self_rotate(vector<int>::iterator beg, vector<int>::iterator end) {
        int temp;
        while (beg < end - 1) {
            temp = *beg;
            *beg = *(end-1);
            *(end-1) = temp;
            beg++; end--;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> v = {1,2,3,4,5,6,7};
    sol.rotate(v, 3);
    for (auto e: v) {
        cout << e << ", ";
    }
    cout << endl;
    return 0;
}