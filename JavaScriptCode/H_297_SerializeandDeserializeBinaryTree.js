var l = console.log.bind(console);

function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    let result = [];
    var dfs = root => {
        if (!root) {
            result.push('#');
        } else {
            result.push(root.val);
            dfs(root.left);
            dfs(root.right);
        }
    };
    dfs(root);
    return result.join(' ');
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    if (!data) return null;
    let dataArr = data.split(' ');

    var decode = (idx) => {
        if (idx >= dataArr.length || dataArr[idx] == '#') {
            return [null, idx+1];
        }
        let node = new TreeNode(parseInt(dataArr[idx++]));
        [node.left, idx] = decode(idx);
        [node.right, idx] = decode(idx);
        return [node, idx];
    };
    
    return decode(0)[0];
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */

// var root = new TreeNode(1);
// root.left = new TreeNode(2);
// root.right = new TreeNode(3);
// root.right.left = new TreeNode(4);
// root.right.right = new TreeNode(5);

var root = new TreeNode(1);
root.right = new TreeNode(2);

deserialize(serialize(root));
l(root);