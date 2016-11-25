var l = console.log.bind(console);
/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    var result = [];
    var i = 0;
    
    while (i < words.length) {
        let currLine = [];
        let lineCount = words[i].length;
        currLine.push(words[i++]);
        while (i < words.length && (lineCount+words[i].length+1<=maxWidth)) {
            currLine.push(words[i]);
            lineCount += (words[i].length + 1);
            i++;
        }
        let wsCount = maxWidth - lineCount + currLine.length - 1;
        if (currLine.length == 1) {
            result.push(currLine[0] + " ".repeat(wsCount));
            continue;
        }
        if (i == words.length) {
            result.push(currLine.join(' ') + " ".repeat(maxWidth - lineCount));
            break;
        }
        let basewsCount = Math.floor(wsCount / (currLine.length-1));
        let moreCount = wsCount % (currLine.length-1);
        for (let idx = 1; idx < currLine.length; idx++) {
            let repeatCount = (idx <= moreCount ? basewsCount+1 : basewsCount); 
            currLine[idx] = " ".repeat(repeatCount) + currLine[idx];
        }
        result.push(currLine.join(''));
    }

    return result;
};


// var words = ["This", "is", "an", "example", "of", "text", "justification."];
// var maxWidth = 16;
// var words = ["a","b","c","d","e"];
// var maxWidth = 3;
var words = ["What","must","be","shall","be."];
var maxWidth = 12;

l(fullJustify(words, maxWidth));