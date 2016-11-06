#include "lc_header.h"

using namespace std;

class comp{
public:
    bool operator()(tuple<int, int, int>&a, tuple<int, int, int> &b){
        return get<2>(a) > get<2>(b);
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int len = matrix.size() < k ? matrix.size() : k;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> heap;
        for (int i = 0; i < len; ++i) {
            heap.push(make_tuple(0, i, matrix[0][i]));
        }
        tuple<int, int, int> curr;
        for (int i = 0; i < k; ++i) {
            curr = heap.top();
            heap.pop();
            if (get<0>(curr) == matrix.size() - 1) {
                continue;
            }
            int next_row = get<0>(curr) + 1;
            int next_col = get<1>(curr);
            heap.push(make_tuple(next_row, next_col, matrix[next_row][next_col]));
        }
        return get<2>(curr);
    }
};