#include "lc_header.h"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) {
            return 0;
        }
        int left = 1, right = x;
        int mid = left + (right - left) / 2;
        int x_mid = x / mid;
        while (mid != x_mid && left < right - 1) {
            if (mid < x_mid) {
                left = mid;
            } else {
                right = mid;
            }
            mid = left + (right - left) / 2;
            x_mid = x / mid;
        }
        return mid;
    }
};