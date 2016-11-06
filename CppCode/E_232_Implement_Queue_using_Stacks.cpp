#include "lc_header.h"
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        for (int ele : queue) {
            stack.emplace_back(queue.back());
            queue.pop_back();
        }
        stack.emplace_back(x);
        for (int ele : stack) {
            queue.emplace_back(stack.back());
            stack.pop_back();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        queue.pop_back();
    }

    // Get the front element.
    int peek(void) {
        return queue.back();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return queue.empty();
    }

private:
    vector<int> stack, queue;
};