#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, k;
        cin >> n >> k;
        vector<int> sums;
        int sum = 0;
        vector<long> remainders(k, 0);
        remainders[0]++;
        for (size_t i = 0; i < n; i++) {
            int num;
            cin >> num;
            sum = (sum+num) % k;
            sums.push_back(sum);
            remainders[sum]++;
        }
        long long res = 0;
        for (size_t j = 0; j < k; j++) {
            res += (remainders[j] * (remainders[j]-1)) / 2;
        }
        cout << res << endl;
    }
    return 0;
}
