#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        results.clear();
        combination.clear();    
        backtracking_helper(candidates, target, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> combination;
    void backtracking_helper(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            results.emplace_back(combination);
            return;
        }
        for (int i = idx; i < candidates.size() && target >= candidates[i]; i++) {
            if (i == idx || candidates[i-1] != candidates[i]) {
                combination.emplace_back(candidates[i]);
                backtracking_helper(candidates, target-candidates[i], i+1);
                combination.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> in = {10, 1, 2, 7, 6, 1, 5};
    auto ret =  sol.combinationSum2(in, 8);
    for (auto row : ret) {
        for (auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}