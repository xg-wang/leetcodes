#include "lc_header.h"
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n_row = words.size();
        for (size_t row = 0; row < n_row; row++) {
            int n_col = words[row].size();
            if (n_col > n_row) return false;
            size_t col = row + 1;
            for (;col < n_row; col++) {
                if (col < n_col) {
                    if (words[row][col] != words[col][row]) return false;
                } else {
                    if (words[col].size() > row) return false;
                }
            }
        } 
        return true;
    }
};