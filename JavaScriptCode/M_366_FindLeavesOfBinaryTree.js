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
var findLeaves = function(root) {
    const result = [];

    var insertLeaves = node => {
        if (!node) { return 0; }
        const level = Math.max(insertLeaves(node.left), insertLeaves(node.right));
        if (level == result.length) { result.push([]); }
        result[level].push(node.val);
        return level + 1;
    };

    insertLeaves(root);
    return result;
};

var findLeaves = function(root) {
    var result = [];

    var insertLeaves = function(node) {
        if (!node) { return 0; }
        var level = Math.max(insertLeaves(node.left), insertLeaves(node.right));
        if (level == result.length) { result.push([]); }
        result[level].push(node.val);
        return level + 1;
    };

    insertLeaves(root);
    return result;
};