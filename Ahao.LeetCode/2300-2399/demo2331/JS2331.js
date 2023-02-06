var evaluateTree = function (root) {
    if (!root.left) {
        return root.val === 1;
    }
    if (root.val === 2) {
        return evaluateTree(root.left) || evaluateTree(root.right);
    } else {
        return evaluateTree(root.left) && evaluateTree(root.right);
    }
};


function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}