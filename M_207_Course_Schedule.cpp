#include "lc_header.h"
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> on_stack(numCourses, false);
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto p: prerequisites) {
            g[p.first].push_back(p.second);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && !dfs(i, g, visited, on_stack)) {
                return false;
            }
        }
        return true;
    }
    
    bool dfs(int course, const vector<vector<int>>& g, vector<bool>& v, vector<bool>& o) {
        v[course] = true;
        o[course] = true;
        for (auto next: g[course]) {
            if (o[next] || (!v[next] && !dfs(next, g, v, o))) {
                return false;
            }
        }
        o[course] = false;
        return true;
    }
};