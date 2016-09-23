#include "lc_header.h"
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> history(n, vector<int>(n, 0));
        return _min_cost(1, n, history);
    }

private:
    int _min_cost(int beg, int end, vector<vector<int>>& history) {
        if (beg >= end) return 0;
        if (history[beg - 1][end - 1] > 0) { 
            return history[beg - 1][end - 1];
        }

        int min_cost = INT_MAX;
        for (int i = beg; i <= end; i++) {
            int curr_cost = i + 
                max(_min_cost(beg, i - 1, history), _min_cost(i + 1, end, history));
            if (curr_cost < min_cost) {
                min_cost = curr_cost;
            }
        }
        history[beg - 1][end - 1] = min_cost;
        return min_cost;
    }
};
// class Solution {
// public:
//     int getMoneyAmount(int n) {
//         // {total cost, number of guesses}
//         vector<tuple<int, int>> history;
//         if (n < 2) {
//             return 0;
//         } else {
//             history.push_back(make_tuple(0, 0));
//         };
//         if (n == 2) {
//             return 1;
//         } else {
//             history.push_back(make_tuple(1, 1));
//         };
//         if (n == 3) {
//             return 2;
//         } else {
//             history.push_back(make_tuple(2, 1));
//         };

//         for (int i = 4; i <= n; i++) {
//             history.push_back(get_result(i, history));
//         }
//         return get<0>(history.back());
//     }

// private:
//     tuple<int, int> get_result(int n, vector<tuple<int, int>>& history) {
//         tuple<int, int> min_choice = make_tuple(INT_MAX, 0);
//         for (int i = 2; i < n; i++) {
//             int left_cost = get<0>(history[i-2]);
//             int right_cost = get<0>(history[n-i-1]) + get<1>(history[n-i-1]) * i;
//             int curr_cost = i;
//             int curr_guesses = 1;
//             if (left_cost > right_cost) {
//                 curr_cost += left_cost;
//                 curr_guesses += get<1>(history[i-2]);
//             } else {
//                 curr_cost += right_cost;
//                 curr_guesses += get<1>(history[n-i-1]);
//             }
//             if (curr_cost > get<0>(min_choice)) continue;
//             if (curr_cost < get<0>(min_choice) || curr_guesses < get<1>(min_choice)) {
//                 min_choice = make_tuple(curr_cost, curr_guesses);
//             }
//         }
//         return min_choice;
//     }
// };

int main() {
    Solution sol;
    cout << sol.getMoneyAmount(6) << endl;
}