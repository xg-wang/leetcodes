#include "lc_header.h"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
        int idx1 = m - 1, idx2 = n - 1;
        int i;
        for (i = m + n - 1; idx1 >= 0 && idx2 >= 0; --i) {
            if (nums1[idx1] > nums2[idx2]) {
                nums1[i] = nums1[idx1--];
            } else {
                nums1[i] = nums2[idx2--];
            }
        }
        if (idx1 < 0) {
            for (; i >= 0; --i) {
                nums1[i] = nums2[i];
            }
        }
    }
};