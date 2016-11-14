#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (B.size() < 1) return vector<vector<int>>();
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        for (int r = 0; r < A.size(); r++) {
            vector<int>& row = A[r];
            vector<int>& res_row = res[r];
            for (int i = 0; i < row.size(); i++) {
                if (row[i] != 0) {
                    for (int j = 0; j < res_row.size(); j++) {
                        res_row[j] += row[i] * B[i][j];
                    }
                }
            }
        }
        return res;
    }
};