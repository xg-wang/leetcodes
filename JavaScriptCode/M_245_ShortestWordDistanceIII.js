/**
 * @param {string[]} words
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var shortestWordDistance = function(words, word1, word2) {
    let len = words.length;
    let p1  = -len, p2 = -len, minDis = len;
    const eq = word1 == word2;
    for (let i = 0; i < len; i++) {
        if (words[i] == word1) {
            if (eq) p2 = p1;
            p1 = i;
            minDis = Math.min(minDis, p1 - p2);
        } else if (words[i] == word2) {
            p2 = i;
            minDis = Math.min(minDis, p2 - p1);
        } else {
            continue;
        }
    }
    return minDis;
};
