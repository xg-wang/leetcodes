#include "lc_header.h"

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> cache;
        return compute_helper(input, cache);
    }

private:
    vector<int> compute_helper(string input, unordered_map<string, vector<int>>& cache) {
        vector<int> result;
        int len = input.size();
        for (int i = 0; i < len; ++i) {
            vector<int> res1, res2;
            char op = input[i];
            if (op == '+' || op == '-' || op == '*') {
                string sub = input.substr(0, i);
                if (cache.find(sub) != cache.end()) {
                    res1 = cache[sub];
                } else {
                    res1 = compute_helper(sub, cache);
                }

                sub = input.substr(i + 1);
                if (cache.find(sub) != cache.end()) {
                    res2 = cache[sub];
                } else {
                    res2 = compute_helper(sub, cache);
                }

                for (int e1 : res1) {
                    for (int e2 : res2) {
                        result.push_back(compute_with_op(e1, e2, op));
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(stoi(input));
        }
        cache[input] = result;
        return result;
    }
    int compute_with_op(int a, int b, char op) {
        switch (op) {
            case '*': return a * b;
            case '-': return a - b;
            case '+': return a + b;
            default: return 0;
        }
    }
};