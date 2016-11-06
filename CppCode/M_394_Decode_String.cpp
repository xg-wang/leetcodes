#include "lc_header.h"
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "", curr_str = "";
        stack<int> nums;
        stack<string> strs;
        if (s.empty()) return res;
        string::iterator it = s.begin();
        while (it < s.end()) {
            nums.emplace(get_num(it));
            if (*it == '[') {
                it++;
            }
            strs.emplace(get_str(it));
            if (it == s.end()) break;
            while (it < s.end() && *it == ']') {
                curr_str = strs.top();
                for (int i = 1; i < nums.top(); i++) {
                    curr_str += strs.top();
                }
                strs.pop();
                nums.pop();
                if (!strs.empty()) {
                    curr_str = strs.top() + curr_str;
                    strs.pop();
                } else {
                    nums.push(1);
                }
                strs.emplace(curr_str);
                it++;
            }
        }
        while (!strs.empty() && !nums.empty()) {
            curr_str = strs.top();
            for (int i = 1; i < nums.top(); i++) {
                curr_str += strs.top();
            }
            res = curr_str + res;
            strs.pop();
            nums.pop();
        }
        return res;
    }

private:
    int get_num(string::iterator& it) {
        int res = 0;
        while (*it >= '0' && *it <= '9') {
            res = 10*res + ((*it) - '0');
            it++;
        }
        return res == 0 ? 1 : res;
    }
    string get_str(string::iterator& it) {
        string::iterator end = it, beg = it;
        while (*end >= 'a' && *end <= 'z') {
            end++;
        }
        it = end;
        return string(beg, end);
    }
};

int main() {
    Solution sol;
    cout << sol.decodeString("sd2[f2[e]g]i") << endl;
    cout << sol.decodeString("3[a]2[bc]") << endl;
}