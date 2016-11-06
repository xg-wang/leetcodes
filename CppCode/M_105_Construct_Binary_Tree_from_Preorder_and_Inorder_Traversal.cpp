#include "lc_header.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() < 1) {
            return NULL;
        }
        
        stack<TreeNode*> sp;
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *ret = root;
        sp.push(root);
        size_t i = 0;
        for (size_t p = 0; p < preorder.size(); p++) {
            if (preorder[p] != inorder[i]) {
                root->left = new TreeNode(preorder[p+1]);
                root = root->left;
                sp.push(root);
            } else {
                while (!sp.empty() && sp.top()->val == inorder[i]) {
                    i++;
                    root = sp.top();
                    sp.pop();
                }
                if (p < preorder.size()-1) {
                    root->right = new TreeNode(preorder[p+1]);
                    root = root->right;
                    sp.push(root);
                }
            }
        }
        
        return ret;
    }
};