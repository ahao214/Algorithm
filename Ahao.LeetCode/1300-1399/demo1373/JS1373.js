﻿const INF = 0x3f3f3f3f;
var maxSumBST = function (root) {
    const dfs = (root) => {
        if (!root) {
            return new SubTree(true, INF, -INF, 0);
        }
        let left = dfs(root.left);
        let right = dfs(root.right);

        if (left.isBST && right.isBST && root.val > left.maxValue && root.val < right.minValue) {
            const sum = root.val + left.sumValue + right.sumValue;
            res = Math.max(res, sum);
            return new SubTree(true, Math.min(left.minValue, root.val), Math.max(root.val, right.maxValue), sum);
        } else {
            return new SubTree(false, 0, 0, 0);
        }
    }
    let res = 0;
    dfs(root);
    return res;
};

class SubTree {
    constructor(isBST, minValue, maxValue, sumValue) {
        this.isBST = isBST;
        this.minValue = minValue;
        this.maxValue = maxValue;
        this.sumValue = sumValue;
    }
}