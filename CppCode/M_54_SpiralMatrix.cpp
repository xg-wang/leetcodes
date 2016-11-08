#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if (rows <= 0) return res;
        int cols = matrix[0].size();
        int n = min(rows, cols);
        for (int i = 0; i < (n + 1) / 2; ++i) {
            //cout << "top" << endl;
            for (int top = i; top < cols - i; ++top) {
                res.push_back(matrix[i][top]);
                //cout << res.back() << ", " << endl;
            }
            //cout << "right" << endl;
            for (int right = i + 1; right < rows - i - 1; right++) {
                res.push_back(matrix[right][cols - i - 1]);
                //cout << res.back() << ", " << endl;
            }
            if (rows - i - 1 <= i) continue;
            //cout << "bottom" << endl;
            for (int bottom = cols - i - 1; bottom >= i; bottom--) {
                res.push_back(matrix[rows - i - 1][bottom]);
                //cout << res.back() << ", " << endl;
            }
            if (i >= cols - i - 1) continue;
            //cout << "left" << endl;
            for (int left = rows - i - 2; left > i; left--) {
                res.push_back(matrix[left][i]);
                //cout << res.back() << ", " << endl;
            }
        }
        return res;
    }
};