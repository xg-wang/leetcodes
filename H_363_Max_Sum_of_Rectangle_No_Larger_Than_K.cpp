#include "lc_header.h"
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) {
            return 0;
        }
        int h = matrix.size();
        int w = matrix[0].size();
        
        int res = INT_MIN;
        if (h < w) {
            for (int lower = 0; lower < h; lower++) {
                vector<int> v(w);
                for (int higher = lower; higher < h; higher++) {
                    for (int i = 0; i < w; i++) {
                        v[i] += matrix[higher][i];
                    }
                    res = max(res, MaxSumNoMoreThanK_1d(v, k));
                    if (res == k) return k;
                }
            }
        } else {
            for (int lower = 0; lower < w; lower++) {
                vector<int> v(h);
                for (int higher = lower; higher < w; higher++) {
                    for (int j = 0; j < h; j++) {
                        v[j] += matrix[j][higher];
                    }
                    res = max(res, MaxSumNoMoreThanK_1d(v, k));
                    if (res == k) return k;
                }
            }
        }
        return res;
    }
    int MaxSumNoMoreThanK_1d(vector<int>& v, int k) {
        int sum = 0, maxSum = INT_MIN;
        set<int> sumset;
        sumset.insert(0);
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
            maxSum = max(sum, maxSum);
            if (maxSum == k ) return maxSum;
            if (sum < 0) sum = 0;
        }
        if (maxSum <= k) return maxSum;
        maxSum = INT_MIN;
        sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
            auto sit = sumset.lower_bound(sum - k);
            if (sit != sumset.end()) {
                maxSum = max(maxSum, sum - *sit);
            }
            sumset.insert(sum);
        }
        return maxSum;
    }
};