﻿var evaluateTree = function (root) {
    if (!root.left) {
        return root.val === 1;
    }
    if (root.val === 2) {
        return evaluateTree(root.left) || evaluateTree(root.right);
    } else {
        return evaluateTree(root.left) && evaluateTree(root.right);
    }
};
