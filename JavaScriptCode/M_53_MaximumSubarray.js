/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let suffix = -Infinity, max = -Infinity;
    for (let n of nums) {
        suffix = Math.max(suffix + n, n);
        max = Math.max(max, suffix);
    }
    return max;
};