#include "lc_header.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows < 1) {
            return ret;
        }
        ret.push_back({1});
        if (numRows == 1) {
            return ret;
        }
        for (int i = 1; i < numRows; ++i) {
            vector<int> current_row = {1};
            current_row.resize(i + 1);
            for (int curr_idx = 1; curr_idx < i; ++curr_idx) {
                current_row[curr_idx] = ret.back()[curr_idx - 1] + ret.back()[curr_idx];
            }
            current_row[i] = 1;
            ret.push_back(current_row);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> v = sol.generate(5);
    for (int i = 0; i < v.size(); ++i) {
        cout << "[";
        for (auto ele: v[i]) {
            cout << ele << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}