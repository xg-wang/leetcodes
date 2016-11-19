#include "lc_header.h"
using namespace std;

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return root;
        TreeNode *l = root->left, *r = root->right;
        root->left = nullptr;
        root->right = nullptr;
        while (l) {
            TreeNode *tl = l->left, *tr = l->right;
            l->left = r;
            l->right = root;
            root = l;
            l = tl;
            r = tr;
        }
        return root;
    }
};