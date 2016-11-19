/**
 * @param {number[][]} costs
 * @return {number}
 */
var minCost = function(costs) {
    if (costs.length < 1) return 0;
    let prevMins = [0,0,0];
    let currMins = [0,0,0];
    for (let c of costs) {
        currMins[0] = c[0] + Math.min(prevMins[1], prevMins[2]);
        currMins[1] = c[1] + Math.min(prevMins[0], prevMins[2]);
        currMins[2] = c[2] + Math.min(prevMins[0], prevMins[1]);
        prevMins = currMins.slice();
    }
    return Math.min(currMins[0], Math.min(currMins[1], currMins[2]));
};