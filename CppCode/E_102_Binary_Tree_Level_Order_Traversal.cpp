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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        res.emplace_back();
        queue<pair<TreeNode*, int>> q;
        q.emplace(make_pair(root, 0));
        int level = 0;
        while (!q.empty()) {
            auto pnode = q.front();
            q.pop();
            if (pnode.second != level) {
                level++;
                res.emplace_back();
            }
            res.back().push_back(pnode.first->val);
            if (pnode.first->left) {
                q.emplace(pnode.first->left, level+1);
            }
            if (pnode.first->right) {
                q.emplace(pnode.first->right, level+1);
            }
        }
        
        return res;
    }
};