#include "lc_header.h"

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n;
        int mid = (left + right) / 2;
        int result = guess(mid);
        while (result != 0) {
            if (result > 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            mid = (left + right) / 2;
            result = guess(mid);
        }
        return mid;
    }
};