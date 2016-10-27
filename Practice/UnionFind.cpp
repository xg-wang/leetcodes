#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent;
    vector<int> size;
    int count;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n);
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int p) {
        int root = p;
        while (root != parent[root]) {
            root = parent[root];
        }
        while (p != root) {
            int newP = parent[p];
            parent[p] = root;
            p = newP;
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

