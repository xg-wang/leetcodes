/**
 * @param {number[]} houses
 * @param {number[]} heaters
 * @return {number}
 */
var findRadius = function(houses, heaters) {
    let minR = 0;
    heaters.sort((a, b) => a - b);
    for (let house of houses) {
        let idx = bs(heaters, 0, heaters.length-1, house);
        let r = Math.abs(house - heaters[idx]);
        if (idx > 0) {
            r = Math.min(r, Math.abs(house - heaters[idx-1]));
        }
        // console.log(`house: ${house}, r: ${r}, idx: ${idx}`);
        minR = Math.max(minR, r);
    }
    return minR;
};
var bs = function(arr, l, r, target) {
    if (l >= r) return l;
    let m = l + Math.floor((r-l) / 2);
    if (arr[m] >= target) {
        if (m === l || arr[m-1] < target) {
            return m;
        } else {
            return bs(arr, l, m-1, target); 
        }
    } else {
        return bs(arr, m+1, r, target);
    }
};