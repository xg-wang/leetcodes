/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var largestBSTSubtree = function(root) {
    return countSubtree(root)[0];
};
var countSubtree = function(root) {
    if (!root) return [0, Infinity, -Infinity];
    let l = countSubtree(root.left), r = countSubtree(root.right);
    let v = root.val;
    if (v > l[2] && v < r[1]) {
        return [1 + l[0] + r[0], 
                root.left  ? l[1] : root.val,
                root.right ? r[2] : root.val];
    } else {
        return [Math.max(l[0], r[0]), -Infinity, Infinity];
    }
}