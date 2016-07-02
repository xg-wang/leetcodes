// https://leetcode.com/problems/valid-anagram/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> s_map, t_map;
        for (auto ch: s) {
            s_map[ch]++;
        }
        for (auto ch: t) {
            t_map[ch]++;
        }
        if (s_map.size() != t_map.size()) {
            return false;
        } else {
            for(const auto &ch_pair: s_map) {
                if (ch_pair.second != t_map[ch_pair.first]) {
                    return false;
                }
            }
            return true;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    cout << solver.isAnagram("aa", "a") << endl;
    return 0;
}