#include "lc_header.h"

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int curr = n / 2, prev = n;
        while (true) {
            if (isBadVersion(curr)) {
                prev = curr;
                curr = curr / 2;
            } else {
                if (curr > prev - 2) {
                    break;
                }
                curr = curr + (prev - curr) / 2;
            }
        }
        return prev;
    }
};