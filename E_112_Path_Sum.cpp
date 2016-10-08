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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        } else if (root->left || root->right) {
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        } else if (sum == root->val) {
            return true;
        } else {
            return false;
        }
    }
};