/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    if (nums.length < 1) return 0;
    let max = -Infinity, min = 0, cur = 0;
    for (let n of nums) {
        if (n > 0) {
            min = (min === 0 ? 0 : min * n);
            cur = (cur <=  1 ? n : cur * n);
        } else if (n < 0) {
            let tempMin = min;
            min = (cur <=  1 ? n : cur * n);
            cur = (tempMin === 0 ? n : tempMin * n);
        } else {
            min = 0;
            cur = 0;
        }
        max = Math.max(max, cur);
        // console.log(`max = ${max}, min = ${min}, cur = ${cur}`);
    }
    return max;
};