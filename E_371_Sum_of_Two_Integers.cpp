#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        bool last_a, last_b, carry;
        int result = 0;
        last_a = a & 1;
        last_b = b & 1;
        a = a >> 1;
        b = b >> 1;
        carry = 0;
        for (int i = 0; i < sizeof(int) * 8; ++i) {
            result |= (last_a ^ last_b ^ carry) << i;
            carry = (last_a && last_b) || (last_a && carry) || (last_b && carry);
            last_a = a & 1;
            last_b = b & 1;
            a = a >> 1;
            b = b >> 1;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    std::cout << solver.getSum(1, 2) << std::endl;
    return 0;
}