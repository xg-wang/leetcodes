/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    // O(NlogN)
    if (nums.length === 0) return 0;
    let lis = Array.of(nums[0]), len = 1;
    for (let [i, n] of nums.entries()) {
        if (n < lis[0]) {
            lis[0] = n;
        } else if (n > lis[len-1]) {
            lis[len++] = n;
        } else {
            lis[binarySearchCeiling(lis, 0, len-1, n)] = n;
        }
    }
    return len;
    
    // O(N^2)
    // if (nums.length === 0) return 0;
    // let lis = Array(nums.length).fill(1), maxLen = 1;
    // for (let i = 1; i < nums.length; i++) {
    //     let n = nums[i];
    //     for (let j = 0; j < i; j++) {
    //         if (n > nums[j] && lis[i] <= lis[j]) {
    //             lis[i] = lis[j] + 1;
    //         }
    //     }
    //     maxLen = Math.max(maxLen, lis[i]);
    // }
    // return maxLen;
};