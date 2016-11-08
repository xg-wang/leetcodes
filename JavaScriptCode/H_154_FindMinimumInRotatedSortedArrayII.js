/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    var helper = function(left, right) {
        if (left >= right) return nums[left];
        let mid = left + Math.floor((right-left)/2);
        let m = nums[mid], l = nums[left], r = nums[right];
        if (l < r) {
            return l;
        } else if (m <= r && m < nums[mid-1]) {
            return m;
        } else if (m > r) {
            return helper(mid+1, right);
        } else if (m < l) {
            return helper(left, mid-1);
        } else {
            return Math.min(helper(mid+1, right), helper(left, mid-1));
        }
    };
    return helper(0, nums.length-1);
};

console.log(findMin([3,3,1,3]));
console.log(findMin([3,3,1,3,3,3,3]));
