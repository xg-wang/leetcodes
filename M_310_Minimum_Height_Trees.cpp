#include "lc_header.h"
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n < 2) return vector<int>(1);
        vector<unordered_set<int>> g(n);
        for (auto e: edges) {
            g[e.first].insert(e.second);
            g[e.second].insert(e.first);
        }
        unordered_set<int> leaves;
        for (int i=0; i< g.size(); i++) {
            if (g[i].size() == 1) {
                leaves.insert(i);
            }
        }
        // for (auto l = leaves.begin(); l != leaves.end(); l++) {
        //     cout << *l << ", ";
        // }
        // cout << endl;
        while (n > 2) {
            int n_leaves = leaves.size();
            //cout << n_leaves << endl;
            n -= n_leaves;
            unordered_set<int> new_leaves;
            for (auto l = leaves.begin(); l != leaves.end(); l++) {
                //cout << "in leaf " << *l << endl;
                if (g[*l].size() == 1) {
                    auto n = g[*l].begin();
                    //cout << "l = " << *l << " next = " << *n << endl;
                    if (g[*n].size() == 2) {
                        new_leaves.insert(*n);
                    }
                    g[*n].erase(*l);
                }
                // for (auto n = g[*l].begin(); n != g[*l].end(); n++) {
                //     cout << "l = " << *l << " next = " << *n << endl;
                //     new_leaves.insert(*n);
                //     g[*n].erase(*l);
                // }
            }
            leaves.swap(new_leaves);
        }
        return vector<int>(leaves.begin(), leaves.end());
    }
};