#include "lc_header.h"
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for (size_t i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};