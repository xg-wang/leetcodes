#include "lc_header.h"
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() < 1) return 0;
        if (grid[0].size() < 1) return 0;
        vector<int> top(grid[0].size(), INT_MAX);
        top[0] = 0;
        int curr = 0;

        for (size_t i = 0; i < grid.size(); i++) {
            curr = grid[i][0] + top[0];
            top[0] = curr;
            vector<int> *curr_row = &grid[i];
            for (size_t j = 1; j < grid[i].size(); j++) {
                curr = (curr < top[j] ? curr : top[j]) + (*curr_row)[j];
                top[j] = curr;
            }
        }

        return curr;
    }
};