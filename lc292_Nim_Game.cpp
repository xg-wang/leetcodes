#include <iostream>

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solver;
    std::cout << solver.canWinNim(7) << std::endl;
    return 0;
}