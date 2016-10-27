#include "lc_header.h"
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() < 1) return true;
        stack<int> s;
        int parent = INT_MIN;
        for (int i =0; i < preorder.size(); i++) {
            if (parent >= preorder[i]) return false;
            while (!s.empty() && preorder[i] > s.top()) {
                parent = s.top();
                s.pop();
            }
            s.push(preorder[i]);
        }
        return true;
    }
};