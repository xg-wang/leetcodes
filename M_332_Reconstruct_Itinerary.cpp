#include "lc_header.h"
using namespace std;

class Solution {
public:
    int airports;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> g;
        for (auto p: tickets) {
            g[p.first][p.second]++;
        }
        vector<string> itinerary;
        airports = tickets.size() + 1;
        dfs("JFK", g, itinerary);
        return itinerary;
    }
    void dfs(const string& airport, unordered_map<string, map<string, int>>& g, vector<string>& itinerary) {
        itinerary.emplace_back(airport);
        for (auto& next: g[airport]) {
            if (next.second > 0) {
                next.second--;
                dfs(next.first, g, itinerary);
                if (itinerary.size() == airports) {
                    return;
                } else {
                    next.second++;
                }
            }
        }
        if (itinerary.size() != airports) {
            itinerary.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<pair<string, string>> in = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    for (const auto& s: sol.findItinerary(in)) {
        cout << s << " ";
    }
    cout << endl;
}