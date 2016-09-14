#include "lc_header.h"

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long ret = 0;
        string::const_iterator it = str.begin();
        while (it != str.end() && *it == ' ') {
            it++;
        }
        bool is_negative = false;
        if (*it == '+' || *it == '-') {
            is_negative = (*it == '-');
            it++;
        }
        while (it != str.end() && is_valid_digit(*it)) {
            ret *= 10;
            ret += (*it) - '0';
            it++;
            if (!is_negative && ret >= INT_MAX) {
                return INT_MAX;
            } else if (is_negative && -1*ret <= INT_MIN) {
                return INT_MIN;
            }
        }
        ret = is_negative ? -1 * ret : ret;

        return ret;
    }

private:
    bool is_valid_digit(char c) {
        return c >= '0' && c <= '9';
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << "1 = " << sol.myAtoi("1") << endl;
    cout << "-123 = " << sol.myAtoi("-123") << endl;
    cout << "abc1 = " << sol.myAtoi("abc1") << endl;
    cout << "1.23 = " << sol.myAtoi("   1.23") << endl;
    cout << "2147483648 = " << sol.myAtoi("2147483648") << endl;
    cout << "2147483648 = " << atoi("2147483648") << endl;
    return 0;
}