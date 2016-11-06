#include "lc_header.h"

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> hash(10, 0);
        vector<bool> equal(secret.size(), false);
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
                equal[i] = true;
            } else {
                hash[secret[i] - '0']++;
            }
        }
        for (int i = 0; i < guess.size(); ++i) {
            if (!equal[i]) {
                if (hash[guess[i] - '0']-- > 0) {
                    cows++;
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << (sol.getHint("11", "10") == "1A0B") << endl;
    return 0;
}