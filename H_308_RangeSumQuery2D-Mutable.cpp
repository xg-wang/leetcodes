class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        bits.resize(matrix.size());
        m = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            bits[i].resize(matrix[i].size() + 1);
            for (int j = 0; j < matrix[i].size(); j++) {
                rowAdd(bits[i], j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        rowAdd(bits[row], col, val - m[row][col]);
        m[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int j = row1; j <= row2; j++) {
            sum += (rowSum(bits[j], col2) - rowSum(bits[j], col1 - 1));
        }
        return sum;
    }
private:
    vector<vector<int>> bits;
    vector<vector<int>> m;
    void rowAdd(vector<int>& bit, int col, int val) {
        col++;
        while (col < bit.size()) {
            bit[col] += val;
            col += (col & -col);
        }
    }
    int rowSum(vector<int>& bit, int col) {
        col++;
        int sum = 0;
        while (col > 0) {
            sum += bit[col];
            col -= (col & -col);
        }
        return sum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);