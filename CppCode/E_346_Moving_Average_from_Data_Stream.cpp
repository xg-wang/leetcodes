#include "lc_header.h"
using namespace std;

class MovingAverage {
public:
    queue<int> q;
    int window_size;
    int curr_size;
    int sum;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window_size = size;
        curr_size = 0;
        sum = 0;
    }
    
    double next(int val) {
        if (curr_size++ >= window_size) {
            sum -= queue.front();
            queue.pop()
            curr_size--;
        }
        sum += val;
        queue.push(val);
        return sum / curr_size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */