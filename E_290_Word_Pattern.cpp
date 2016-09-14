#include "lc_header.h"

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str, ' ');
        if (words.size() != pattern.size()) {
            return false;
        }
        unordered_map<char, string> map;
        for (int i = 0; i < pattern.size(); ++i) {
            if (map.find(pattern[i]) == map.end()) {
                for (const auto& ele : map) {
                    if (ele.second == words[i]) {
                        return false;
                    }
                }
                map[pattern[i]] = words[i];
            } else if (map[pattern[i]] != words[i]) {
                return false;
            }
        }
        return true;
    }

private:
    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss;
        ss.str(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}