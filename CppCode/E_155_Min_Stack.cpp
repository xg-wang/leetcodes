#include "lc_header.h"
using namespace std;

// should use long to prevent overflow
// use gap to avoid extra stack

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (rel_stack.empty()) {
            min = x;
        }
        rel_stack.push(x - min);
        if (x < min) {
            min = x;
        }
    }
    
    void pop() {
        if (rel_stack.empty()) {
            return;
        }
        long t = rel_stack.top();
        rel_stack.pop();
        if (t < 0) {
            min -= t;
        }
    }
    
    int top() {
        long t = rel_stack.top();
        if (t < 0) return min;
        return rel_stack.top() + min;
    }
    
    int getMin() {
        return (int)min;
    }
  
private:
    stack<long> rel_stack;
    long min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */