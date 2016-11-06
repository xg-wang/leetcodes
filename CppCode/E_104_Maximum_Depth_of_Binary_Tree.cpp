#include <iostream>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ?
            1 + maxof(maxDepth(root->left), maxDepth(root->right)) :
            0;
    }

private:
    bool maxof(int l, int r) {
        return l > r ? l : r;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    std::cout << solver.maxDepth(arg) << std::endl;
    return 0;
}