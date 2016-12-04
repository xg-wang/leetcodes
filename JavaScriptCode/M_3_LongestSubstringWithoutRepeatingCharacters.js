/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let longestCount = 0, suffixCount = 0;
    let charsMap = new Map();
    let len = s.length;
    for (let i = 0; i < len && len-i+suffixCount > longestCount; i++) {
        if (charsMap.has(s[i]) && charsMap.get(s[i]) >= i-suffixCount) {
            longestCount = Math.max(longestCount, suffixCount);
            suffixCount = i - charsMap.get(s[i]) - 1;
        }
        charsMap.set(s[i], i);
        suffixCount++;
    }
    longestCount = Math.max(longestCount, suffixCount);
    return longestCount;
};

console.log(lengthOfLongestSubstring("abcabcbb"));