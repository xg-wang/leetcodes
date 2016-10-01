#include "lc_header.h"
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 0;
        for(int num = 0; num < n; num++) {
            vector<int> digits(num + 1);
            for (int pos = 0; pos < num; pos++) {
                for (int i = 0; i < 10; i++) {
                    if (!conflict_at_position(i, pos, digits)) {
                        digits[pos] = i;
                        result++;
                    }
                }
            }
        }
        return result;
    }
private:
    bool conflict_at_position(int curr_digit, int pos, vector<int>& digits) {
        for (size_t i = 0; i < pos; i++) {
            if (digits[i] == curr_digit) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.countNumbersWithUniqueDigits(2) 
         << " (should be 91)" << endl;
}