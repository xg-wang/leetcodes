/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
var robSubtree = function(root) {
    if (!root) return [0, 0];
    let left = robSubtree(root.left);
    let right = robSubtree(root.right);
    return [
        root.val + left[1] + right[1],
        Math.max(Math.max(...left) + Math.max(...right))
    ];
};
/**
 * @param {TreeNode} root
 * @return {number}
 */
var rob = function(root) {
    return Math.max(...robSubtree(root));
};