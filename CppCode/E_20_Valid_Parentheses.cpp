#include "lc_header.h"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (size_t i = 0; i < s.size(); i++) {
            char curr = s[i];
            if (is_left(curr)) {
                stack.push_back(curr);
            } else if (!is_right(curr) || !can_pair(stack, curr)) {
                return false;
            } else {
                stack.pop_back();
            }
        }
        return stack.empty();
    }

private:
    bool is_left(char c) {
        return c == '(' || c == '[' || c == '{'; 
    }
    bool is_right(char c) {
        return c == ')' || c == ']' || c == '}'; 
    }
    bool can_pair(vector<char>& s, char c) {
        if (s.size() < 1) return false;
        char l = s.back();
        switch (c) {
            case ')': if (l == '(') return true;
            case ']': if (l == '[') return true;
            case '}': if (l == '{') return true;
            default: return false;
        } 
    }
};