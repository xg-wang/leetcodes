// https://leetcode.com/problems/add-digits/
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    int addDigits(int num) {
        return 1 + ((num - 1) % 9);
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    std::cout << solver.addDigits(38) << std::endl;
    return 0;
}