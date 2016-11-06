#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> curr_row(target+1, vector<vector<int>>());
        vector<bool> flags(target+1, false);
        flags[0] = true;

        for (size_t i = 1; i <= candidates.size(); i++) {
            int curr_candidate = candidates[i-1];
            for (int j = target; j > 0; j--) {
                int k = 1;
                while (j >= k * curr_candidate) {
                    if (flags[j - k*curr_candidate]) {
                        flags[j] = true;
                        if (curr_row[j-k*curr_candidate].size() == 0) {
                            curr_row[j-k*curr_candidate].push_back(vector<int>());
                        }
                        for (auto c : curr_row[j - k*curr_candidate]) {
                            curr_row[j].emplace_back(c);
                            int count_k = k;
                            while (count_k-- > 0) {
                                curr_row[j].back().emplace_back(curr_candidate);
                            }
                        }
                    }
                    k++;
                }
            }
        }
        return curr_row[target];
    }
};

int main() {
    Solution sol;
    vector<int> in = {2,3,6,7};
    auto ret =  sol.combinationSum(in, 7);
    for (auto row : ret) {
        for (auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}