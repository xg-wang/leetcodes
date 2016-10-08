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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> stack;
        if (!root) return res;
        dfs(root, sum, stack, res);
        return res;
    }
    void dfs(TreeNode* root, int sum, vector<int>& stack, vector<vector<int>>& res) {
        if (!root) {
            return;
        }
        stack.push_back(root->val);
        if (sum == root->val && !root->left && !root->right) {
            res.emplace_back(stack);
        } else {
            dfs(root->left, sum - root->val, stack, res);
            dfs(root->right, sum - root->val, stack, res);
        }
        stack.pop_back();
        return;
    }
};