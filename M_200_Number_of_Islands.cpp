#include "lc_header.h"
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, visited);
                    res++;
                }
            }
        }
        return res;
    }

private:
    void dfs(int i, int j, const vector<vector<char>>& g, vector<vector<bool>>& v) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || v[i][j]) {
            return;
        }
        v[i][j] = true;
        if (g[i][j] == '1') {
            dfs(i+1, j, g, v);
            dfs(i, j+1, g, v);
            dfs(i-1, j, g, v);
            dfs(i, j-1, g, v);
        }
    }
};