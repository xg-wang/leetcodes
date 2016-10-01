#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        results.clear();
        combination.clear();
        backtracking_helper(k, n, 1);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> combination;
    void backtracking_helper(int k, int n, int idx) {
        if (k == 0 && n == 0) {
            results.emplace_back(combination);
            return;
        }
        for (int i = idx; i <= n && i < 10; i++) {
            combination.emplace_back(i);
            backtracking_helper(k-1, n-i, i+1);
            combination.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> in = {10, 1, 2, 7, 6, 1, 5};
    auto ret =  sol.combinationSum3(3, 9);
    for (auto row : ret) {
        for (auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}