/**
 * @param {string[]} strs
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var findMaxForm = function(strs, m, n) {
    strs = strs.sort((a, b) => {return a.length - b.length;});
    // console.log(strs);
    let used = new Set();
    let maxCount = 0;
    let updates = strs.map(str => {
        return str.split('').reduce((acc, cur) => {
            if (cur === "1") {
                acc[1]++;
            } else if (cur === "0") {
                acc[0]++;
            }
            return acc;
        }, [0, 0]);
    });
    
    var bt = function(m, n) {
        if (m === 0 && n === 0) {
            maxCount = Math.max(maxCount, used.size);
            return;
        }
        for (let i = 0; i < strs.length; i++) {
            if (!used.has(i)) {
                used.add(i);
                let newM = m - updates[i][0], newN = n - updates[i][1];
                let total = newM + newN;
                if (total < 0 || total/strs[i].length < maxCount-used.size) {
                    used.delete(i);
                    break;
                }
                if (newM >= 0 && newN >= 0) {
                    maxCount = Math.max(maxCount, used.size);
                    // console.log(`str=${strs[i]}, newM=${newM}, newN=${newN}`);
                    // console.log(`maxCount=${maxCount}`);
                    bt(newM, newN);
                }
                used.delete(i);
            }
        }
    };
    
    bt(m, n);
    return maxCount;
};