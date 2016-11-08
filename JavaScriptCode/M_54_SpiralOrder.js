/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let result = [];
    if (matrix === null || matrix.length === 0 || matrix[0].length === 0){
        return result;
    }
    const rows = matrix.length;
    const cols = matrix[0].length;
    const n = Math.min(rows, cols);
    for (let i = 0; i < (n + 1) / 2; i++) {
        for (let top = i; top < cols - i; top++) {
            result.push(matrix[i][top]);
        }
        for (let right = i + 1; right < rows - i - 1; right++) {
            result.push(matrix[right][cols - i - 1]);
        }
        if (rows - i - 1 <= i) continue;
        for (let bottom = cols - i - 1; bottom >= i; bottom--) {
            result.push(matrix[rows - i - 1][bottom]);
        }
        if (i >= cols - i - 1) continue;
        for (let left = rows - i - 2; left > i; left--) {
            result.push(matrix[left][i]);
        }
    }
    return result;
};

console.log(spiralOrder([[6,9,7]]));