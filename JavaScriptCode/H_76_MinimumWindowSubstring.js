/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    let map = {};
    t.split('').forEach(ch => {
        map[ch] = (map[ch] || 0) + 1;
    });
    let charCount = t.length, l = 0, minL = 0, dis = s.length;
    for (let i = 0; i < s.length; i++) {
        if (s[i] in map && map[s[i]]-- > 0) {
            charCount--;
            while (charCount === 0) {
                if (s[l] in map && map[s[l]]++ === 0) {
                    charCount++;
                    if (i - l < dis) {
                        minL = l;
                        dis = i - l;
                    }
                }
                l++;
            }
        }
    }
    return dis === s.length ? "" : s.substr(minL, dis+1);
};