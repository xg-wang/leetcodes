/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
var fourSumCount = function(A, B, C, D) {
    let map = new Map();
    for (let a of A) {
        for (let b of B) {
            map.set(a + b, (map.get(a+b) || 0) + 1);
        }
    }
    let count = 0;
    for (let c of C) {
        for (let d of D) {
            let n = map.get(-c-d);
            if (n) {
                count += n;
            }
        }
    }
    return count;
};