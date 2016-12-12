/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    let smap = new Map(), tmap = new Set();
    for (let i = 0; i < s.length; i++) {
        if (!smap.has(s[i]) && !tmap.has(t[i])) {
            smap.set(s[i], t[i]);
            tmap.add(t[i]);
        } else if (smap.get(s[i]) !== t[i]) {
            return false;
        }
    }
    return true;
};