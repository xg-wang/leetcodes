#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> onStack(numCourses, false);
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> res;
        // build graph
        for (auto p: prerequisites) {
            g[p.first].push_back(p.second);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && !dfs(i,visited,onStack,g,res)) {
                return vector<int>();
            }
        }
        return res;
    }

private:
    bool dfs(int course, vector<bool>& v, vector<bool>& o, vector<vector<int>>& g, vector<int>& to) {
        v[course] = true;
        o[course] = true;
        for (auto n: g[course]) {
            if (!v[n] && !dfs(n,v,o,g,to) || o[n]) {
                return false;
            }
        }
        o[course] = false;
        to.push_back(course);
        return true;
    }
};