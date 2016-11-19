class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(n, 2, result, path);
        return result;
    }
    void backtrack(int num, int start, vector<vector<int>>& result, vector<int>& path) {
        while (start * start <= num) {
            if (num % start == 0) {
                int remain = num / start;
                path.push_back(start);
                path.push_back(remain);
                result.emplace_back(path);
                path.pop_back();
                backtrack(remain, start, result, path);
                path.pop_back();
            }
            start++;
        }
    }
};