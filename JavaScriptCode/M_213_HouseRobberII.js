var robLinear = function(nums, beg, end) {
    let includeLast = 0, excludeLast = 0;
    for (let i = beg; i < end; i++) {
        let temp = includeLast;
        includeLast = nums[i] + excludeLast;
        excludeLast = Math.max(temp, excludeLast);
    }
    return Math.max(includeLast, excludeLast);
}
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let len = nums.length;
    if (len === 0) return 0;
    if (len === 1) return nums[0];
    return Math.max(robLinear(nums, 0, len-1), robLinear(nums, 1, len));
};