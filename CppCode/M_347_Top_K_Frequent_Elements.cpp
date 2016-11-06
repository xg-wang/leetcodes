// https://leetcode.com/problems/top-k-frequent-elements/

#include "lc_header.h"

using namespace std;

class Solution {
private:
    void printheap(vector<pair<int, int>> &heap) {
        for (auto ele: heap) {
            cout << "value: " << ele.second << ",freq: " << ele.first << "; ";
        }
        cout << endl;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequent_map;
        for (int n: nums) {
            frequent_map[n]++;
        }
        vector<pair<int, int>> heap;
        auto it = frequent_map.begin();
        for (int i = 0; i < k; i++) {
            heap.push_back({it->second, it->first});
            it++;
        }
        make_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
        printheap(heap);
        for (size_t i = k; i < frequent_map.size(); i++) {
            printheap(heap);
            if (it->second > heap.front().first) {
                pop_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
                heap.pop_back();
                printheap(heap);
                heap.push_back({it->second, it->first});
                push_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
                printheap(heap);
            }
            it++;
        }
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(heap[i].second);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> in = {4,1,-1,2,-1,2,3};
    for (auto ele: sol.topKFrequent(in, 2)) {
        cout << ele << endl;
    }
    cout << endl;
    vector<int> in2 = {3,0,1,0};
    for (auto ele: sol.topKFrequent(in2, 1)) {
        cout << ele << endl;
    }
    return 0;
}