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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            return helper(root);
        }
    }
    int helper(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return 0;
        } 
        if (root->left && !root->left->left && !root->left->right) {
            return root->left->val + helper(root->right);
        } else {
            return helper(root->left) + helper(root->right);
        }
    } 
};