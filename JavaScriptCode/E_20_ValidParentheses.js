/**
 * @param {string}
 * @return {boolean}
 */
var isValid = function(s) {
    const lDic = ['(', '{', '['];
    const rDic = [')', '}', ']'];
    let stack = [];
    for (let c of s) {
        if (rDic.includes(c)) {
            if (stack.length === 0 || lDic.indexOf(stack.pop()) != rDic.indexOf(c)) {
                return false;
            }
        } else {
            stack.push(c);
        }
    }
    return stack.length === 0;
};