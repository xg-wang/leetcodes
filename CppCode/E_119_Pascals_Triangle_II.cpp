#include "lc_header.h"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr_row, last_row;
        if (rowIndex < 0) {
            return curr_row;
        }
        curr_row.push_back(1);
        if (rowIndex == 0) {
            return curr_row;
        }
        for (int i = 0; i < rowIndex; ++i) {
            curr_row.swap(last_row);
            curr_row.clear();
            curr_row.push_back(1);
            for (int last_idx = 1; last_idx < last_row.size(); ++last_idx) {
                curr_row.push_back(last_row[last_idx - 1] + last_row[last_idx]);
            }
            curr_row.push_back(1);
        }
        return curr_row;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> v = sol.getRow(4);
    cout << "[";
    for (auto ele: v) {
        cout << ele << ",";
    }
    cout << "]" << endl;
    return 0;
}