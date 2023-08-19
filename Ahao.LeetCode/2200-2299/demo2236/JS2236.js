
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

var checkTree = function (root) {
    return root.val === root.left.val + root.right.val;
};
