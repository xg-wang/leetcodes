#include "lc_header.h"
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        parent.resize(n);
        size.resize(n);
        unordered_map<int, int> s;
        count = n;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (s.count(curr)) continue;
            parent[i] = i;
            size[i] = 1;
            s[curr] = i;
            if (s.count(curr - 1)) {
                unite(i, s[curr - 1]);
            }
            if (s.count(curr + 1)) {
                unite(i, s[curr + 1]);
            }
        }
        int maxsize = -1;
        for (int i = 0; i < n; i++) {
            maxsize = max(maxsize, size[i]);
        }
        return maxsize;
    }
    
    vector<int> parent;
    vector<int> size;
    int count;

    int find(int p) {
        int root = p;
        while (root != parent[root]) {
            root = parent[root];
        }
        while (p != root) {
            int newp = parent[p];
            parent[p] = root;
            p = newp;
        }
        return root;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    void unite(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        if (rootP == rootQ) return;
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }
};

int main() {
    Solution sol;
    vector<int> in = {1,2,0,1};
    cout << sol.longestConsecutive(in) << endl;
}