/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let s1 = new Set(nums1), s2 = new Set(nums2), s, l;
    let result = [];
    if (s1.size < s2.size) {
        s = s1; l = s2;
    } else {
        s = s2; l = s1;
    }
    for (let e of s) {
        if (l.has(e)) {
            result.push(e);
        }
    }
    return result;
};