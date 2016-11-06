#include "lc_header.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        pair<int,int> l = dfs(root->left);
        pair<int,int> r = dfs(root->right);
        int m = root->val;
        if (l.second > 0) m += l.second;
        if (r.second > 0) m += r.second;
        return max(l.first, max(r.first, m));
    }

    pair<int/*submax*/, int/*connect max*/> dfs(TreeNode *rt) {
        if (!rt) return make_pair(INT_MIN, INT_MIN);
        pair<int,int> res;
        pair<int,int> l = dfs(rt->left), r = dfs(rt->right);
        
        res.second = rt->val;
        int sub = max(l.second, r.second);
        if (sub > 0) res.second += sub;
        
        int m = rt->val;
        if (l.second > 0) m += l.second;
        if (r.second > 0) m += r.second;
        res.first = max(max(l.first, r.first), m);
        return res;
    }
};