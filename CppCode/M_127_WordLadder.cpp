#include "lc_header.h"
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> head, tail;
        unordered_set<string> *shorter, *longer;
        int trans_count = 2;
        if (beginWord == endWord) return trans_count;
        head.insert(beginWord);
        tail.insert(endWord);
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                shorter = &head;
                longer = &tail;
            } else {
                shorter = &tail;
                longer = &head;
            }
            unordered_set<string> new_head;
            for (auto w: *shorter) {
                for (size_t i = 0; i < w.size(); i++) {
                    char backup = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == backup) continue;
                        w[i] = c;
                        if (longer->find(w) != longer->end()) {
                            return trans_count;
                        }
                        if (wordList.find(w) != wordList.end()) {
                            new_head.insert(w);
                            wordList.erase(w);
                        }
                    }
                    w[i] = backup;
                }
            }
            trans_count++;
            shorter->swap(new_head);
        }
        return 0;
    }
};

int main() {
    Solution sol;
    unordered_set<string> in = {"a", "b", "c"};
    unordered_set<string> in2 = {"hot","dot","dog","lot","log"};
    cout << sol.ladderLength("hit", "cog", in2) << endl;
}