#include "lc_header.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (int i = 0; i < magazine.size(); ++i) {
            map[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            if (--map[ransomNote[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};