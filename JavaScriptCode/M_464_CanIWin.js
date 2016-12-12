/**
 * @param {number} maxChoosableInteger
 * @param {number} desiredTotal
 * @return {boolean}
 */
var canIWin = function(maxChoosableInteger, desiredTotal) {
    if (maxChoosableInteger >= desiredTotal) return true;
    if (maxChoosableInteger*(1+maxChoosableInteger)/2 <= desiredTotal) return false;
    let cache = new Map();
    let usedIntegers = Array(maxChoosableInteger).fill(false);

    var dp = function(desiredTotal) {
        if (desiredTotal <= 0) {
            return false;
        }
        if (usedIntegers.lastIndexOf(false)+1 >= desiredTotal) {
            return true;
        }
        let key = compressArr(usedIntegers);
        if (!cache.has(key)) {
            for (let i = 0; i < maxChoosableInteger; i++) {
                if (!usedIntegers[i]) {
                    usedIntegers[i] = true;
                    if (!dp(desiredTotal - i - 1)) {
                        cache.set(key, true);
                        usedIntegers[i] = false;
                        return true;
                    }
                    usedIntegers[i] = false;
                }
            }
            cache.set(key, false);
        }
        return cache.get(key);
    };
    
    return dp(desiredTotal);
};
var compressArr = function(used) {
    let result = 0;
    for (let i = 0; i < used.length; i++) {
        if (used[i] === true) {
            result |= (1 << i);
        }
    }
    return result;
};