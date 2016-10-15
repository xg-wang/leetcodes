#include "lc_header.h"
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, 
                                vector<double>& values, 
                                vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> g;
        for (size_t i = 0; i < equations.size(); i++) {
            g[equations[i].first].insert({equations[i].second, values[i]});
            if (values[i] != 0) {
                g[equations[i].second].insert({equations[i].first, 1/values[i]});
            }
        }
        unordered_map<string, unordered_map<string, double>> answers = g;
        unordered_set<string> v;
        vector<double> res;
        
        for (auto q: queries) {
            if (g.find(q.first) == g.end() || g.find(q.second) == g.end()) {
                res.push_back(-1.0);
            } else {
                res.push_back(dfs(q, g, answers, v));
            }
        }
        return res;
    }
    
    double dfs(const pair<string, string>& q,
               const unordered_map<string, unordered_map<string, double>>& g, 
               unordered_map<string, unordered_map<string, double>>& a,
               unordered_set<string>& v) {
        if (q.first == q.second) return 1.0;
        
        if (a[q.first].count(q.second) != 0) {
            return a[q.first][q.second];
        } else {
            v.insert(q.first);
            for (auto child: a[q.first]) {
                if (v.find(child.first) == v.end()) {
                    dfs({child.first, q.second}, g, a, v);
                }
                if (a[child.first].count(q.second) != 0) {
                    double ans = a[child.first][q.second] * a[q.first][child.first];
                    a[q.first][q.second] = ans;
                    return ans;
                }
            }
            return -1;
        }
    }
};