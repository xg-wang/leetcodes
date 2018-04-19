/**
 * @param {number[]} nums
 * @return {boolean}
 */
var increasingTriplet = function(nums) {
    if (nums.length < 3) return false;
    let m1 = nums[0], m2 = Infinity;
    for (let n of nums) {
        if (n <= m1) {
            m1 = n;
        } else if (n <= m2) {
            m2 = n;
        } else {
            return true;
        }
    }
    return false;
};