var comp = (a, b) => a-b;
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    nums1.sort(comp);
    nums2.sort(comp);
    let s, l, il = 0, result = [];
    if (nums1.length < nums2.length) {
        s = nums1;
        l = nums2;
    } else {
        s = nums2;
        l = nums1;
    }
    for (let e of s) {
        while (il < l.length && l[il] < e) {
            il++;
        }
        if (il === l.length) break;
        if (l[il] === e) {
            result.push(e);
            il++;
        }
    }
    return result;
};