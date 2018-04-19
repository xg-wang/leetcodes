var flip = function(grid, i, j) {
    if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] === "0") {
        return;
    }
    grid[i][j] = "0";
    flip(grid, i-1, j);
    flip(grid, i+1, j);
    flip(grid, i, j-1);
    flip(grid, i, j+1);
};
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    let count = 0;
    for (let [i, row] of grid.entries()) {
        for (let [j, ele] of row.entries()) {
            if (ele === "1") {
                count++;
                flip(grid, i, j);
            }
        }
    }
    return count;
};