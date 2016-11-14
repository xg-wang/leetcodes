#include "lc_header.h"
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int len = words.size();
        int p1 = -len, p2 = -len;
        int min_dis = len;
        for (int i = 0; i < len; i++) {
            if (words[i] == word1) {
                p1 = i;
                min_dis = min(min_dis, p1 - p2);
            } else if (words[i] == word2) {
                p2 = i;
                min_dis = min(min_dis, p2 - p1);
            } else {
                continue;
            }
        }
        return min_dis;
    }
};