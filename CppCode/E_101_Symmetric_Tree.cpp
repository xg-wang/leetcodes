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
class Solution_recursive {
public:
    bool isSymmetric(TreeNode* root) {
        return !root || helper(root->left, root->right);
    }
    bool helper(TreeNode* l, TreeNode* r) {
        return (!l && !r) || ((l && r) && l->val == r->val && helper(l->left, r->right) && helper(l->right, r->left));
    }
};
class Solution_BFS {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push(make_pair(root->left, root->right));
        while (!q.empty()) {
            pair<TreeNode*, TreeNode*> node = q.front();
            q.pop();
            if (node.first==NULL ^ node.second==NULL) {
                return false;
            } else if (node.first && node.second) {
                if (node.first->val != node.second->val) {
                    return false;
                }
                q.push(make_pair(node.first->left, node.second->right));
                q.push(make_pair(node.first->right, node.second->left));
            }
        }
        return true;
    }
};