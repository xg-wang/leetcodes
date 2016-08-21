/*
Given an integer *n*, return 1 - *n* in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
 */

#include "lc_header.h"

using namespace std;

bool is_less_than(int a, int b)
{
    string a_string = to_string(a);
    string b_string = to_string(b);

    size_t char_count = min(a_string.size(), b_string.size());
    for (int i = 0; i < char_count; i++)
    {
        if (a_string[i] < b_string[i]) {
            return true;
        } else if (a_string[i] > b_string[i]){
            return false;
        }
    }
    return (a_string.length() < b_string.length());
}
class Solution {
public:
    vector<int> lexicalOrder_sort(int n) {
        // time exceeds
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = i + 1;
        }
        sort(ret.begin(), ret.end(), is_less_than);
        return ret;
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        ret.reserve(n);

        string n_str = to_string(n);
        size_t len = n_str.size();
        int s = 1;
        for (int i = 0; i < len; ++i) {
            scale.push_back(s);
            s *= 10;
        }
        int depth = 0;
        int base = 0;
        order_helper(ret, depth, base, len, n);
        return ret;
    }

private:
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> scale;

    void order_helper(vector<int> &ret, int depth, int base, size_t len, int n) {
        if (depth == len) return;

        for (int i: vec) {
            if (depth == 0 && i == 0) continue;
            int curr_base = base * 10 + i;
            if (curr_base <= n) {
                ret.push_back(curr_base);
                order_helper(ret, depth + 1, curr_base, len, n);
            } else {
                break;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    for (auto ele: sol.lexicalOrder(13)) {
        cout << ele << ", ";
    }
    cout << endl;
    return 0;
}