/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    var myPowHelper = function(x, n) {
        if (n === 1) return x;
        let remain = n % 2;
        let half = (n - remain) / 2;
        let halfVal = myPowHelper(x, half);
        return halfVal * halfVal * (remain === 1 ? x : 1);
    }
    return n === 0 ? 1 :
                 (n < 0 ? 1 / myPowHelper(x, -n) :
                          myPowHelper(x, n));
};