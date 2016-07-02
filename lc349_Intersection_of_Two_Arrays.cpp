#include <iostream>
#include <vector>
#include <<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_set<int> hash1(nums1.begin(), nums1.end()), hash2(nums2.begin(), nums2.end());
        unordered_set<int> *s, *l;

        if (hash1.size() > hash2.size()) {
            s = &hash2;
            l = &hash1;
        } else {
            s = &hash1;
            l = &hash2;
        }
        for (unordered_set<int>::iterator it = s->begin(); it != s->end(); ++it) {
            if (l->count(*it) > 0) {
                ret.push_back(*it);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    return 0;
}