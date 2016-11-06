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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lh = dfs(root->left);
        if (lh == -1) {
            return -1;
        }
        int rh = dfs(root->right);
        if (rh == -1) {
            return -1;
        }
        if (abs(lh - rh) > 1) {
            return -1;
        }
        
        return max(lh, rh) + 1;
    }
};