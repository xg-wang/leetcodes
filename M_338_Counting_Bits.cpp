// https://leetcode.com/problems/counting-bits/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(1, 0);
        while (num != 0) {
            int temp_size = result.size();
            for (int i = 0; i < temp_size; ++i) {
                result.push_back(1 + result[i]);
                num--;
                if (num == 0) return result;
            }
        }
        return result;
    }
};
