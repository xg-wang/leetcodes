/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    s = s.trim();
    let idxE = s.indexOf('e');
    if (idxE != -1) {
        return isInteger(s.substr(idxE+1)) && isNormalNumber(s.substr(0, idxE));
    } else {
        return isNormalNumber(s);
    }
};
var isInteger = function(s) {
    return /^[+|-]?\d+$/.test(s);
};
var isNormalNumber = function(s) {
    let idxDot = s.indexOf('.');
    if (idxDot != -1) {
        if (idxDot == s.length-1) {
            return isInteger(s.substr(0, s.length-1));
        } else {
            return /^[+|-]?\d*$/.test(s.substr(0,idxDot)) &&
                   /^\d+$/.test(s.substr(idxDot+1));
        }
    } else {
        return isInteger(s);
    }
};