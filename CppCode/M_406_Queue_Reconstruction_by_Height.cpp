#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), recon_compare);
        
        for (size_t i = 0; i < people.size(); i++) {
            int larger_count = 0;
            size_t j = 0;
            for (; j < i; j++) {
                if (people[j].first >= people[i].first) {
                    larger_count++;
                }
                if (larger_count == people[i].second && j < i-1) {
                    j++;
                    break;
                }
            }
            for (; j < i; j++) {
                if (people[j].first >= people[i].first) {
                    break;
                }
            }
            if (j < i) {
                // move people[i] forward to correct position
                for (size_t k = j; k < i; k++) {
                    swap_element(people[k], people[i]);
                }
            }
        }
        
        return people;
    }
    
private:
    static bool recon_compare(pair<int, int> a, pair<int, int> b) {
        if (a.second < b.second) {
            return true;
        } else if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return false;
        }
    }
    void swap_element(pair<int, int>& a, pair<int, int>& b) {
        if (a != b) {
            a.first ^= b.first;
            b.first ^= a.first;
            a.first ^= b.first;
            a.second ^= b.second;
            b.second ^= a.second;
            a.second ^= b.second;
        }
    }
};