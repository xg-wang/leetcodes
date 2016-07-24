// https://leetcode.com/problems/number-of-1-bits/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res;
        while(n){
            if(n & 1 == 1){
                res++;
            }
            n >>= 1;
        }
        return res;
    }

    int hammingWeight1(uint32_t n) {
        int uint32_length = 32;
        return _hammingWeighthelper(n, uint32_length);
    }
private:
    uint32_t one = 0x00000001, zero = 0x00000000;
    uint32_t all_one = 0xffffffff;
    int _hammingWeighthelper(uint32_t n, int curr_length) {
        if (n == zero) {
            return 0;
        } else if (n == one) {
            return 1;
        } else {
            int curr_len_2 = curr_length / 2;
            uint32_t mask = all_one >> (curr_len_2) << (curr_len_2);
            return (
                _hammingWeighthelper(
                    (mask & n) >> (curr_len_2),
                    curr_len_2
                ) +
                _hammingWeighthelper(
                    ~mask & n,
                    curr_len_2
                )
            );
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    cout << "Total count = " << solver.hammingWeight(2) << endl;
    return 0;
}