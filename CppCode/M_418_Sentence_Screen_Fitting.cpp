#include "lc_header.h"
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> words_fit(n);
        for (int i = 0; i < n; ++i) {
            words_fit[i] = wordsCount(sentence, i, cols);
        }
        int words = 0, start = 0;
        for (int i = 0; i < rows; ++i) {
            int row_count = words_fit[start];
            words += row_count;
            start = (start + row_count) % n;
        }
        return words / n;
    }
    int wordsCount(vector<string>& sentence, int start, int cols) {
        int idx = 0, count = -1;
        while (idx < cols + 2) {
            count++;
            int curr_len = sentence[start].size();
            idx += sentence[start].size() + 1;
            start = (start + 1) % sentence.size();
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<string> in = {"f","p","a"};
    cout << sol.wordsTyping(in, 8, 7) << endl;
}