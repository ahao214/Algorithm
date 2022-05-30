﻿function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

//方法一：递归
var sumRootToLeaf = function (root) {
    const dfs = (root, val) => {
        if (!root) {
            return 0;
        }
        val = (val << 1) | root.val;
        if (!root.left && !root.right) {
            return val;
        }
        return dfs(root.left, val) + dfs(root.right, val);
    }
    return dfs(root, 0);
};


//方法二：迭代
var sumRootToLeaf = function (root) {
    const stack = [];
    let val = 0, ret = 0;
    let prev = null;
    while (root || stack.length) {
        while (root) {
            val = (val << 1) | root.val;
            stack.push(root);
            root = root.left;
        }
        root = stack[stack.length - 1];
        if (!root.right || root.right === prev) {
            if (!root.left && !root.right) {
                ret += val;
            }
            val >>= 1;
            stack.pop();
            prev = root;
            root = null;
        } else {
            root = root.right;
        }
    }
    return ret;
};
