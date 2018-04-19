/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @param {Interval} newInterval
 * @return {Interval[]}
 */
var insert = function(intervals, newInterval) {
    let l = [], r = [];
    for (let i of intervals) {
        if (i.end < newInterval.start) {
            l.push(i);
        } else if (i.start > newInterval.end) {
            r.push(i);
        } else {
            newInterval.start = Math.min(newInterval.start, i.start);
            newInterval.end = Math.max(newInterval.end, i.end);
        }
    }
    
    l.push(newInterval);
    l.push(...r);
    return l;
};