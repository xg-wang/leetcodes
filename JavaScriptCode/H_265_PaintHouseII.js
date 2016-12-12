/**
 * @param {number[][]} costs
 * @return {number}
 */
var minCostII = function(costs) {
    if (costs.length <= 0) return 0;
    let mins = costs[0];
    for (let i = 0; i < costs.length-1; i++) {
        let [min, secMin, minIdx] = [mins[0], Infinity, 0];
        for (let j = 1; j < mins.length; j++) {
            if (mins[j] < min) {
                secMin = min;
                min = mins[j];
                minIdx = j;
            } else if (mins[j] < secMin) {
                secMin = mins[j];
            }
        }
        let curr = costs[i+1];
        for (let idx = 0; idx < curr.length; idx++) {
            curr[idx] += (idx == minIdx ? secMin : min);        
        }
        mins = curr;
    }
    return Math.min(...mins);
};