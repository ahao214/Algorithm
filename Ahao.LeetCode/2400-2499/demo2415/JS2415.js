var reverseOddLevels = function (root) {
    let q = [root];
    let isOdd = false;
    while (q.length) {
        if (isOdd) {
            const n = q.length;
            for (let i = 0; i < n / 2; i++) {
                [q[i].val, q[n - 1 - i].val] = [q[n - 1 - i].val, q[i].val];
            }
        }
        const tmp = [...q];
        q = [];
        for (const node of tmp) {
            if (node.left) {
                q.push(node.left);
            }
            if (node.right) {
                q.push(node.right);
            }
        }
        isOdd ^= true;
    }
    return root;
};



var reverseOddLevels = function (root) {
    const dfs = function (root1, root2, isOdd) {
        if (root1 == null) {
            return;
        }
        if (isOdd) {
            [root1.val, root2.val] = [root2.val, root1.val];
        }
        dfs(root1.left, root2.right, !isOdd);
        dfs(root1.right, root2.left, !isOdd);
    };
    dfs(root.left, root.right, true);
    return root;
};


function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}