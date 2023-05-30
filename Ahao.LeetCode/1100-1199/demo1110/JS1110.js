﻿function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}


var delNodes = function (root, to_delete) {
    const toDeleteSet = new Set(to_delete);
    const roots = [];
    dfs(root, true, toDeleteSet, roots);
    return roots;
}

function dfs(node, isRoot, toDeleteSet, roots) {
    if (!node) {
        return null;
    }
    const deleted = toDeleteSet.has(node.val);
    node.left = dfs(node.left, deleted, toDeleteSet, roots);
    node.right = dfs(node.right, deleted, toDeleteSet, roots);
    if (deleted) {
        return null;
    } else {
        if (isRoot) {
            roots.push(node);
        }
        return node;
    }
}
