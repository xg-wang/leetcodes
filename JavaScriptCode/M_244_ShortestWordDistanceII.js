/**
 * @constructor
 * @param {string[]} words
 */
var WordDistance = function(words) {
    this.wordMap = words.reduce( (m, w, i) => {
        m[w] = (m[w] || []).concat(i);
        return m;
    }, {});
};

/**
 * @param {string} word1
 * @param {string} word2
 * @return {integer}
 */
WordDistance.prototype.shortest = function(word1, word2) {
    const vec1 = this.wordMap[word1];
    const vec2 = this.wordMap[word2];
    let i = 0, j = 0, dist = Infinity;
    while( i < vec1.length && j < vec2.length) { 
        dist = Math.min(dist, Math.abs(vec1[i] - vec2[j]));
        vec1[i] < vec2[j] ? i++ : j++;
    }
    return dist;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * var wordDistance = new WordDistance(words);
 * wordDistance.shortest("word1", "word2");
 * wordDistance.shortest("anotherWord1", "anotherWord2");
 */