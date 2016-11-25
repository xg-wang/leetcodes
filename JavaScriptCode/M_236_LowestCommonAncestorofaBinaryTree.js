var l = console.log.bind(console);
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    if (root === p || root === q) {
        return root;
    }
    var stack = [], pstack = null, qstack = null;
    
    var dfs = (root) => {
        if (!root) return;
        stack.push(root);
        if (root === p) pstack = stack.slice();
        if (root === q) qstack = stack.slice();
        if (pstack && qstack) return;
        if (root.left)  dfs(root.left);
        if (pstack && qstack) return;
        if (root.right) dfs(root.right);
        if (pstack && qstack) return;
        stack.pop();
    };

    dfs(root);
    if (!(pstack && qstack)) return root;
    for (var i = 1; i < Math.min(pstack.length, qstack.length); i++) {
        if (pstack[i] !== qstack[i]) return pstack[i-1];
    }
    return i === pstack.length ? 
                 pstack[pstack.length-1] : 
                 qstack[qstack.length-1];
};