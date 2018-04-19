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
var zigzagLevelOrder = function(root) {
    if (!root) return [];
    let result = [], currNodes = [], currVals = [];
    currNodes.push(root);
    currVals.push(root.val);
    while (currNodes.length !== 0) {
        result.push(currVals);
        let nextNodes = [], nextVals = [];
        if (result.length % 2) {
            for (let i = currNodes.length - 1; i >= 0; i--) {
                let r = currNodes[i].right, l = currNodes[i].left;
                if (r) {
                    nextNodes.push(r);
                    nextVals.push(r.val);
                }
                if (l) {
                    nextNodes.push(l);
                    nextVals.push(l.val);
                }
            }
        } else {
            for (let i = currNodes.length - 1; i >= 0; i--) {
                let r = currNodes[i].right, l = currNodes[i].left;
                if (l) {
                    nextNodes.push(l);
                    nextVals.push(l.val);
                }
                if (r) {
                    nextNodes.push(r);
                    nextVals.push(r.val);
                }
            }
        }
        currNodes = nextNodes;
        currVals = nextVals;
    }
    
    return result;
};