/**
 * @param {number} n
 * @return {number[][]}
 */
var getFactors = function(n) {
    const result = [];
    var backtrack = function(num, start, path) {
        while (start * start <= num) {
            if (num % start == 0) {
                let remain = num / start;
                result.push(path.concat([start, remain]));
                backtrack(remain, start, path.concat([start]));
            }
            start++;
        }
    };
    backtrack(n, 2, []);
    return result;    
};

console.log(getFactors(12));