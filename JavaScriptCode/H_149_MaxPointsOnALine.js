/**
 * Definition for a point.
 * function Point(x, y) {
 *     this.x = x;
 *     this.y = y;
 * }
 */
/**
 * @param {Point[]} points
 * @return {number}
 */
var maxPoints = function(points) {
    if (points.length <= 1) return points.length;
    let max = 2;
    let hash = new Set();
    for (let i = 0; i < points.length-1; i++) {
        let p1 = points[i];
        for (let j = i+1; j < points.length; j++) {
            let p2 = points[j];
            let k = (p2.y - p1.y) / (p2.x - p1.x);
            if (!hash.has(k)) {
                let count = points.reduce((acc, cur, idx) => {
                    if (idx !== i && idx !== j) {
                        if ((cur.x===p1.x && cur.y===p1.y) ||
                            (cur.x===p2.x && cur.y===p2.y) ||
                            (isEqual((cur.y-p1.y) / (cur.x-p1.x), k))) acc++;
                    }
                    return acc;
                }, 2);
                max = Math.max(max, count);
                hash.add(k);
            }
        }
    }
    return max;
};
var isEqual = function(a, b) {
    if (!Number.isFinite(a) && !Number.isFinite(b)) {
        return true;
    }
    return a === b;
}