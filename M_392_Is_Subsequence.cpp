#include "lc_header.h"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        string::iterator sl = s.begin(), sr = s.end() - 1;
        string::iterator tl = t.begin(), tr = t.end() - 1;
        return substr_issubsequence(sl, sr, tl, tr);
    }

private:
    bool substr_issubsequence(string::iterator sl, string::iterator sr, 
                              string::iterator tl, string::iterator tr) {
        if (sl > sr) return true;
        if (sl == sr) {
            while (tl <= tr) {
                if (*tl == *sl) {
                    return true;
                } else {
                    tl++;
                }
            }
            return false;
        }

        while (tl <= tr) {
            if (*tl++ == *sl) {
                sl++;
                break;
            }
        }
        while (tl <= tr) {
            if (*tr-- == *sr) {
                sr--;
                break;
            }
        }
        if (tl > tr && sl <= sr) return false;
        return substr_issubsequence(sl, sr, tl, tr);
    }
};

int main() {
    Solution sol;
    cout << sol.isSubsequence("abc", "ahbgde") << endl;
}