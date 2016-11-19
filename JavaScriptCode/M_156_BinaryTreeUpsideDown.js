/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var upsideDownBinaryTree = function(root) {
    if (root === null) return root;
    let l = root.left, r = root.right;
    root.left = null;
    root.right = null;
    while (l !== null) {
        let tl = l.left, tr = l.right;
        l.left = r;
        l.right = root;
        root = l;
        l = tl;
        r = tr;
    }    
    return root;
};
