#include "lc_header.h"
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *p = root;
        build_stack(p);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !min_vals.empty();
    }

    /** @return the next smallest number */
    int next() {
        int n =  min_vals.top();
        min_vals.pop();
        return n;
    }

private:
    stack<int> min_vals;
    void build_stack(TreeNode *p) {
        if (!p) return;
        if (p->right) build_stack(p->right);
        min_vals.push(p->val);
        if (p->left) build_stack(p->left);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */