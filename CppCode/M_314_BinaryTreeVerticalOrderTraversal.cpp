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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> records;
        queue<pair<int, TreeNode*>> q;
        q.emplace(0, root);
        while (!q.empty()) {
            auto p = q.front();
            if (p.second) {
                records[p.first].push_back(p.second->val);
                q.emplace(p.first - 1, p.second->left);
                q.emplace(p.first + 1, p.second->right);
            }
            q.pop();
        }

        vector<vector<int>> res;
        for (auto p: records) {
            res.emplace_back(p.second);
        }
        return res;
    }

    vector<vector<int>> verticalOrderDFS(TreeNode* root) {
        map<int, vector<int>> records;
        traverseVerticalDFS(root, 0, records);
        vector<vector<int>> res;
        for (auto p: records) {
            res.emplace_back(p.second);
        }
        return res;
    }
    void traverseVerticalDFS(TreeNode* root, int col, map<int, vector<int>>& records) {
        if (!root) return;
        records[col].push_back(root->val);
        traverseVerticalDFS(root->left, col-1, records);
        traverseVerticalDFS(root->right, col+1, records);
    }
};