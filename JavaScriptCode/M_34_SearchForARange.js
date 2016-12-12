/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let left = bsLeft(nums, 0, nums.length-1, target);
    if (nums[left] !== target) return [-1, -1];
    let right = bsLeft(nums, left,nums.length-1, target+1);
    return [left, right <= left ? left : right-1];
};

var bsLeft = function(nums, l, r, target) {
    if (l > r) return l;
    let m = l + Math.floor((r - l) / 2);
    let num = nums[m];
    if (num >= target && (m === l || nums[m-1] < target)) {
        return m;
    } else if (num < target) {
        return bsLeft(nums, m+1, r, target);
    } else {
        return bsLeft(nums, l, m-1, target);
    }
};