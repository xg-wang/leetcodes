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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        stack<TreeNode*> nodes;
        TreeNode *curr = root;
        while (!nodes.empty() || curr) {
            if (curr) {
                nodes.push(curr);
                curr = curr->left;
            } else {
                res.push_back(nodes.top()->val);
                curr = nodes.top()->right ? nodes.top()->right : NULL;
                nodes.pop();
            }
        }
        
        return res;
    }
};