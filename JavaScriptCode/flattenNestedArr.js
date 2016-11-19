var arr = [1,[2,3,[4]]];
function flattenArr(arr) {
    return arr.reduce( (prev, curr) => {
        if (Array.isArray(curr)) {
            return prev.concat(flattenArr(curr));
        } else {
            prev.push(curr);
            return prev;
        }
    }, []);
}

console.log(flattenArr(arr));