/**
 * Definition for an interval.
 */
 function Interval(start, end) {
     this.start = start;
     this.end = end;
 }

/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
var merge = function(intervals) {
    if (intervals.length <= 1) return intervals;
    intervals.sort( (a, b) => a.start - b.start );
    let result = [];
    result.push(intervals[0]);
    for (let i = 1; i < intervals.length; i++) {
        let last = result[result.length-1];
        if (last.end < intervals[i].start) {
            result.push(intervals[i]);
        } else {
            last.end = Math.max(intervals[i].end, last.end);
        }
    }
    return result;
};