const buckets = anagramBuckets(['star', 'arc', 'rac', 'rat', 'rats', 'car']);

function anagramBuckets(input) {
    const result = [];
    const hash = {};

    for (let i = 0; i < input.length; i++) {
        const word = input[i];
        const sortedWord = word.split('').sort().join();
        
        if (!hash[sortedWord]) {
            hash[sortedWord] = [];
        }

        hash[sortedWord].push(word);
    }

    return Object.values(hash);
}

function anagramBuckets2(input) {
    const result = [];
    const hash = {};

    for (let i = 0; i < input.length; i++) {
        const word = input[i];
        const sortedWord = word.split('').sort().join();
        
        if (!hash[sortedWord]) {
            hash[sortedWord] = [];
            result.push(hash[sortedWord]);
        }
        hash[sortedWord].push(word);
    }

    return result;
}

console.log(buckets);
