/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    if (nums.length === 0) return [];
    if (nums.length === 1) return [[nums[0]]];
    let result = [];
    for (let i = 0; i < nums.length; i++) {
        let spliced = nums.slice();
        spliced.splice(i, 1);
        let remains = permute(spliced);
        for (let p of remains) {
            result.push([nums[i]].concat(p));
        }
    }
    return result;
};