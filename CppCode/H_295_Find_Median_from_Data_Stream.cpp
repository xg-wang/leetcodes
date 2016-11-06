#include "lc_header.h"
using namespace std;

class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> least_heap;
    // Adds a number into the data structure.
    void addNum(int num) {
        if (!least_heap.size() && !max_heap.size()) {
            max_heap.push(num);
        } else if (max_heap.top() < num) {
            least_heap.push(num);
        } else {
            max_heap.push(num);
        }
        while (max_heap.size() > least_heap.size()+1) {
            least_heap.push(max_heap.top());
            max_heap.pop();
        }
        while (max_heap.size() < least_heap.size()) {
            max_heap.push(least_heap.top());
            least_heap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (max_heap.size() == least_heap.size()) {
            return (max_heap.top() + least_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();