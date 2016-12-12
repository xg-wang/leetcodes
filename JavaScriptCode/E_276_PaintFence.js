/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var numWays = function(n, k) {
    if (n <= 0 || k <= 0) return 0;
    if (k == 1) return n < 3 ? 1 : 0;
    if (n < 3) return Math.pow(k, n);
    let k_1 = k - 1;
    let psame = k, pdiff = k * k_1, res = psame + pdiff;
    for (let i = 3; i <= n; i++) {
        psame = pdiff;
        pdiff = res * k_1;
        res = psame + pdiff;
    }
    return res;
};