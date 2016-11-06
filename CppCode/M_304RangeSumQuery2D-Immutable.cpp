#include "lc_header.h"
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> presum;    
    NumMatrix(vector<vector<int>> &matrix) {
        presum = matrix;
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                int left = (j==0 ? 0 : presum[i][j-1]);
                int up = (i==0 ? 0 : presum[i-1][j]);
                int upleft = (i==0||j==0 ? 0 : presum[i-1][j-1]);
                presum[i][j] += up + left - upleft;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = (col1==0 ? 0 : presum[row2][col1-1]);
        int up = (row1==0 ? 0 : presum[row1-1][col2]);
        int upleft = (row1==0||col1==0 ? 0 : presum[row1-1][col1-1]);
        return presum[row2][col2] - up - left + upleft;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);