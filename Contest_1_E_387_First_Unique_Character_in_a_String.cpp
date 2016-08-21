/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.

Note: You may assume the string contain only lowercase letters.
 */

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) {
            return -1;
        }
        unordered_map<char, int> char_count;
        for (int i = 0; i < s.size(); ++i) {
            char_count[s[i]]++;
        }
        for (int j = 0; j < s.size(); ++j) {
            if (char_count[s[j]] == 1) {
                return j;
            }
        }
        return -1;
    }
};