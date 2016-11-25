/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    var sm = {};
    var tm = {};
    for (let i = 0; i < s.length; i++) {
        let currs = s[i], currt = t[i];
        if (sm[currs] == undefined) {
            if (currt in tm) return false;
            tm[currt] = null;
            sm[currs] = currt;
        } else if (currt != sm[currs]) {
            return false;
        }
    }
    return true;
};