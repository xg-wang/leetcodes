// https://leetcode.com/problems/intersection-of-two-arrays-ii/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        unordered_map<int, int> m1, m2;
        for (auto e: nums1) {
            m1[e]++;
        }
        for (auto e: nums2) {
            m2[e]++;
        }

        unordered_map<int, int> *s, *l;
        if (m1.bucket_count() > m2.bucket_count()) {
            s = &m2;
            l = &m1;
        } else {
            s = &m1;
            l = &m2;
        }
        for (const auto& pair_s: *s) {
            auto it_l = l->find(pair_s.first);
            if (it_l != l->end()) {
                for (int i = 0; i < min(it_l->second, pair_s.second); i++) {
                    result.push_back(pair_s.first);
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    vector<int> v1 = {1}, v2 = {1};
    vector<int> sol = solver.intersect(v1, v2);
    for (auto e: sol) {
        cout << e << endl;
    }
    return 0;
}