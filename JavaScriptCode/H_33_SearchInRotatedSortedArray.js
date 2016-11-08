/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
  var helper = function(left, right) {
    if (left > right) return -1;
    let mid = left + Math.floor((right-left) / 2);
    let l = nums[left], m = nums[mid], r = nums[right];
    if (m == target) return mid;
    if (l <= m) {
      if (target <= m && target >= l) {
        return helper(left, mid-1);
      } else {
        return helper(mid+1, right);
      }
    } else if (target >= m && target <= r) {
      return helper(mid+1, right);
    } else {
      return helper(left, mid-1);
    }
  };
  return helper(0, nums.length-1);
};

var searchIterative = function(nums, target) {
  let left = 0, right = nums.length-1;
  while ( left <= right) {
    let mid = left + Math.floor((right-left) / 2);
    let l = nums[left], m = nums[mid], r = nums[right];
    if (m == target) return mid;
    if (l <= m) {
      if (target <= m && target >= l) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else if (target >= m && target <= r) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
};

console.log("search([4,5,6,7,8,1,2,3], 8) = " + search([4,5,6,7,8,1,2,3], 8));
console.log("search([5,1,3], 3) = " + search([5,1,3], 3));
console.log("search([3,5,1], 3) = " + search([3,5,1], 3));