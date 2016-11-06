#include "lc_header.h"
using namespace std;

class HitCounter {
public:
    deque<pair<int, int>> q;
    int count;
    /** Initialize your data structure here. */
    HitCounter() {
        q.clear();
        count = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (q.empty() || q.back().first != timestamp) {
            q.emplace_back(timestamp, 1);
        } else {
            q.back().second++;
        }
        count++;
        shrink(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        shrink(timestamp);
        return count;
    }

    void shrink(int timestamp) {
        while (!q.empty() && q.front().first <= timestamp - 300) {
            count -= q.front().second;
            q.pop_front();
        }
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */