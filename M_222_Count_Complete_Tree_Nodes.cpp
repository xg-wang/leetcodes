#include "lc_header.h"

using namespace std;

class Solution {
public:
    int countNodes_recursive(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int level = 1;
        TreeNode *p_right = root;
        TreeNode *p_left = root;
        while (p_right->right) {
            p_right = p_right->right;
            p_left = p_left->left;
            level++;
        }
        if (!p_left->left) {
            return pow(2, level) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};