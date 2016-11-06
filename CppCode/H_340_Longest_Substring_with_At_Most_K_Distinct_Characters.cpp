#include "lc_header.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> m;
        int max_len = 0, l = 0;
        for (int r = 0; r < s.size(); r++) {
            m[s[r]]++;
            while (m.size() > k) {
                m[s[l]]--;
                if (m[s[l]] == 0) {
                    m.erase(s[l]);
                }
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }

    int lengthOfLongestSubstringKDistinct2(string s, int k) {
        if (s.size() < 1 || k < 1) return 0;
        unordered_map<char, int> m;
        int l = 0, r = 0;
        int max_len = 1;
        for (; l < s.size() - max_len; l++) {
            while (m.size() <= k && r < s.size()) {
                m[s[r]]++;
                r++;
            }
            int curr_len = (m.size()>k ? r-l-1: r-l); 
            max_len = max(max_len, curr_len);
            if (--m[s[l]] == 0 ) {
                m.erase(s[l]);
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstringKDistinct("aa", 1) << endl;
}