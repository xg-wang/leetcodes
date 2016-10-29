#include "lc_header.h"
using namespace std;

class SolutionRecursive {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) return s.size() == 0;
        if (p.size() > 1 && p[1] == '*') {
            if (p[0] == '.' || p[0] == s[0]) {
                return isMatch(s, p.substr(2)) || 
                       (!s.empty() && isMatch(s.substr(1), p)) ||
                       (!s.empty() && isMatch(s.substr(1), p.substr(2)));
            } else {
                return isMatch(s, p.substr(2));
            }
        } else if (p[0] != '.' && p[0] != s[0]) {
            return false;
        } else {
            return !s.empty() && isMatch(s.substr(1), p.substr(1));
        }
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        return partialMatch(s, p, s.size()-1, p.size()-1);
    }
private:
    bool partialMatch(string& s, string& p, int is, int ip) {
        if (is < 0) {
            if (ip < 0) return true;
            if (ip > 0 && p[ip] == '*') {
                return partialMatch(s, p, is, ip-2);
            } else return false;
        } else if (ip < 0) {
            return false;
        }
        if (!charEqual(s[is], p[ip])) {
            return false;
        } else {
            if (p[ip] == '*') {
                if (charEqual(s[is], p[ip-1])) {
                    return partialMatch(s, p, is-1, ip) || 
                           partialMatch(s, p, is-1, ip-2) || 
                           partialMatch(s, p, is, ip-2);
                } else {
                    return partialMatch(s, p, is, ip-2);
                }
            }
            return partialMatch(s, p, is-1, ip-1); 
        }
        return true;
    }
    bool charEqual(char a, char b) {
        return a == b || b == '.' || b == '*';
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("aaa", "ab*a*c*a") << endl;
}