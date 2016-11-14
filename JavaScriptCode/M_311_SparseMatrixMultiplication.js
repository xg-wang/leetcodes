/**
 * @param {number[][]} A
 * @param {number[][]} B
 * @return {number[][]}
 */
var multiply = function(A, B) {
  let res = [];
  if (!A.length || !B.length) return res;
  let cols = B[0].length;
  for (let r = 0; r < A.length; r++) {
    let row = A[r];
    let res_row = Array(cols).fill(0);
    for (let i = 0; i < row.length; i++) {
      if (row[i] !== 0) {
        for (let j = 0; j < res_row.length; j++) {
          res_row[j] += row[i] * B[i][j];
        }
      }
    }
    res.push(res_row);
  }
  return res;
};