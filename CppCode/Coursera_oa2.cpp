#include "lc_header.h"
using namespace std;

/*
 * Complete the function below.
 */
int palindrome(string str) {
    unordered_set<string> s;
    size_t n = str.size();
    for (size_t i = 0; i < n; i++) {
        s.insert(str.substr(i, 1));
        for (size_t j = i + 1; j < n; j++) {
            int left = i, right = j;
            while (left < right) {
                if (str[left] != str[right]) break;
                left++; right--;
            }
            if (i >= j) {
                s.insert(str.substr(i, j-i+1));
            }
        }
    }

    return s.size();
}
