function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

//深度优先
var addOneRow = function (root, val, depth) {
    if (!root) {
        return null;
    }
    if (depth === 1) {
        return new TreeNode(val, root, null);
    }
    if (depth === 2) {
        root.left = new TreeNode(val, root.left, null);
        root.right = new TreeNode(val, null, root.right);
    } else {
        root.left = addOneRow(root.left, val, depth - 1);
        root.right = addOneRow(root.right, val, depth - 1);
    }
    return root;
};


//广度优先
var addOneRow = function (root, val, depth) {
    if (depth === 1) {
        return new TreeNode(val, root, null);
    }
    let curLevel = [];
    curLevel.push(root);
    for (let i = 1; i < depth - 1; i++) {
        const tmp = [];
        for (const node of curLevel) {
            if (node.left) {
                tmp.push(node.left);
            }
            if (node.right) {
                tmp.push(node.right);
            }
        }
        curLevel = tmp;
    }
    for (const node of curLevel) {
        node.left = new TreeNode(val, node.left, null);
        node.right = new TreeNode(val, null, node.right);
    }
    return root;
};
