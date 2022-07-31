function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}


//深度优先
var maxLevelSum = function (root) {
    const sum = [];
    const dfs = (node, level) => {
        if (level === sum.length) {
            sum.push(node.val);
        } else {
            sum.splice(level, 1, sum[level] + node.val);
        }
        if (node.left) {
            dfs(node.left, level + 1);
        }
        if (node.right) {
            dfs(node.right, level + 1);
        }
    }
    dfs(root, 0);
    let ans = 0;
    for (let i = 0; i < sum.length; ++i) {
        if (sum[i] > sum[ans]) {
            ans = i;
        }
    }
    return ans + 1; // 层号从 1 开始
};




//广度优先
var maxLevelSum = function (root) {
    let ans = 1, maxSum = root.val;
    let q = [];
    q.push(root);
    for (let level = 1; q.length > 0; ++level) {
        const nq = [];
        let sum = 0;
        for (const node of q) {
            sum += node.val;
            if (node.left) {
                nq.push(node.left);
            }
            if (node.right) {
                nq.push(node.right);
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
            ans = level;
        }
        q = nq;
    }
    return ans;
};
