#include "lc_header.h"
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size()+1, 0);
        multimap<long, int> hashmap;
        for (size_t i = 1; i < sums.size(); i++) {
            sums[i] = sums[i-1] + nums[i-1];
            hashmap.insert(make_pair(sums[i], i));
        }
        int count = 0;
        for (int i = 0; i < sums.size(); i++) {
            for (auto it = hashmap.lower_bound(sums[i] + lower); it != hashmap.end() && it->first <= sums[i] + upper; it++) {
                if (it->second > i) {
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution_MergeSort {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size()+1, 0);
        for (int i = 1; i < sums.size(); i++) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        return countWithMergeSort(sums, 0, sums.size(), lower, upper);
    }
    int countWithMergeSort(vector<long>& sums, int beg, int end, int lower, int upper) {
        int mid = beg + (end - beg) / 2;
        if (mid == beg) return 0;
        int i = mid, j = mid;
        int count = countWithMergeSort(sums, beg, mid, lower, upper) +
                    countWithMergeSort(sums, mid, end, lower, upper);
        for (int left = beg; left < mid; left++) {
            while (i < end && sums[i] <= sums[left] + upper) i++;
            while (j < end && sums[j] < sums[left] + lower) j++;
            count += (i - j);
        }
        inplace_merge(sums.begin()+beg, sums.begin()+mid, sums.begin()+end);
        return count;
    }
};