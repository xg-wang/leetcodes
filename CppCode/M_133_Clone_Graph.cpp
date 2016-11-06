#include "lc_header.h"
using namespace std;
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_set<int> newed;
        return dfs(node, newed);
    }
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_set<int>& newed) {
        if (!node) return node;
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        newed.insert(new_node->label);
        for (auto n: node->neighbors) {
            auto it = newed.find(n->label);
            if (it == newed.end()) {
                UndirectedGraphNode *new_neighbor = new UndirectedGraphNode(n->label);
                new_node->neighbors.push_back(new_neighbor);
                newed.insert(new_neighbor->label);
                dfs(new_neighbor, newed);
            } else {
                new_node->neighbors.emplace_back(*it);
            }
        }
        
        return new_node;
    }
};

int main() {
    Solution sol;
    sol.cloneGraph(NULL);
}