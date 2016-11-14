/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var verticalOrder = function(root) {
    let res = [];
    if (root === null) return res;
    
    let records = {};
    let queue = [];
    queue.push([0, root]);
    let min = Infinity, max = -Infinity;
    while (queue.length) {
        let p = queue.shift();
        if (p[1] !== null) {
            records[p[0]] = records[p[0]] || [];
            records[p[0]].push(p[1].val);
            min = Math.min(min, p[0]);
            max = Math.max(max, p[0]);
            queue.push([p[0]-1, p[1].left]);
            queue.push([p[0]+1, p[1].right]);
        }
    }
    while (min <= max) {
        if (records[min].length) {
            res.push(records[min]);
        }
        min++;
    }
    return res;
};