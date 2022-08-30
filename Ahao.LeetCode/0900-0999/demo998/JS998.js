function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
};

var insertIntoMaxTree = function (root, val) {
    let parent = null;
    let cur = root;
    while (cur) {
        if (val > cur.val) {
            if (!parent) {
                return new TreeNode(val, root, null);
            }
            let node = new TreeNode(val, cur, null);
            parent.right = node;
            return root;
        } else {
            parent = cur;
            cur = cur.right;
        }
    }
    parent.right = new TreeNode(val);
    return root;
};
