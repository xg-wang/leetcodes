#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it_next;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (*it == 0) {
                it_next = it < it_next ? it_next : it + 1;
                while (it_next != nums.end() && *it_next == 0) {
                    ++it_next;
                }
                if (it_next == nums.end()) {
                    return;
                }
                *it = *it_next;
                *it_next = 0;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = { 0, 1, 0, 3, 5};
    Solution sol;

    for (auto e : v) {
        cout << e << ", ";
    }
    cout << endl;

    sol.moveZeroes(v);
    for (auto e : v) {
        cout << e << ", ";
    }
    cout << endl;

    return 0;
}