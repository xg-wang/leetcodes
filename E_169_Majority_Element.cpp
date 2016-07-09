#include "lc_header.h"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, vote = *nums.begin();
        for (vector<int>::iterator i = nums.begin() + 1; i != nums.end(); ++i) {
            if (count != 0) {
                if (vote == *i) {
                    count++;
                } else {
                    count--;
                }
            } else {
                vote = *i;
                count++;
            }
        }
        return vote;
    }
    // int majorityElement(vector<int>& nums) {
    //     int count = 1, vote = *nums.begin();
    //     for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i) {
    //         if (count != 0) {
    //             if (vote == nums[i]) {
    //                 count--;
    //             } else {
    //                 count++;
    //             }
    //         } else {
    //             vote = nums[i];
    //         }
    //     }
    // }
};