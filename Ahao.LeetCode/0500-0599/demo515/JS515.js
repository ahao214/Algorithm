function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}


//深度优先
var largestValues = function (root) {
    if (!root) {
        return [];
    }
    const res = [];
    const dfs = (res, root, curHeight) => {
        if (curHeight === res.length) {
            res.push(root.val);
        } else {
            res.splice(curHeight, 1, Math.max(res[curHeight], root.val));
        }
        if (root.left) {
            dfs(res, root.left, curHeight + 1);
        }
        if (root.right) {
            dfs(res, root.right, curHeight + 1);
        }
    }
    dfs(res, root, 0);
    return res;
};

//广度优先
var largestValues = function (root) {
    if (!root) {
        return [];
    }
    const res = [];
    const queue = [root];
    while (queue.length) {
        let len = queue.length;
        let maxVal = -Number.MAX_VALUE;
        while (len > 0) {
            len--;
            const t = queue.shift();
            maxVal = Math.max(maxVal, t.val);
            if (t.left) {
                queue.push(t.left);
            }
            if (t.right) {
                queue.push(t.right);
            }
        }
        res.push(maxVal);
    }
    return res;
};
