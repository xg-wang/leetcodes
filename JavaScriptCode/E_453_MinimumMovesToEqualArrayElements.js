/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    const min = Math.min(...nums);
    return nums.reduce((prev, curr) => {
        return prev + curr - min; 
    }, 0);
};