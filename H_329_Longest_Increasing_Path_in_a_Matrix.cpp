#include "lc_header.h"
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h < 1) {
            return 0;
        }
        int w = matrix[0].size();
        if (w < 1) {
            return 0;
        }
        vector<vector<int>> visited(h, vector<int>(w, 0));
        int res = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (visited[i][j] == 0) {
                    dfs(i,j,matrix,visited);
                    res = max(res, visited[i][j]);
                }
            }
        }
        return res;
    }
    
    int dfs(int i, int j, vector<vector<int>>& m, vector<vector<int>>& v) {
        if (i<0 || j<0 || i>=m.size() || j>=m[0].size()) {
            return 0;
        }
        if (v[i][j] > 0) {
            return v[i][j];
        } else {
            v[i][j] = 1;    
        }
        int curr_val = m[i][j];
        if (i < m.size()-1    && curr_val < m[i+1][j]) {
            int down  = dfs(i+1,j,m,v);
            v[i][j] = max(down+1, v[i][j]);
        }
        if (j < m[0].size()-1 && curr_val < m[i][j+1]) {
            int right = dfs(i,j+1,m,v);
            v[i][j] = max(right+1, v[i][j]);
        }
        if (i > 0             && curr_val < m[i-1][j]) {
            int up    = dfs(i-1,j,m,v);
            v[i][j] = max(up+1, v[i][j]);
        }
        if (j > 0             && curr_val < m[i][j-1]) {
            int left  = dfs(i, j-1,m,v);
            v[i][j] = max(left+1, v[i][j]);
        }
        
        return v[i][j];
    }
};