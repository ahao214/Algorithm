﻿var maxAncestorDiff = function (root) {
    return dfs(root, root.val, root.val);
};

function dfs(root, mi, ma) {
    if (root === null) {
        return 0;
    }
    var diff = Math.max(Math.abs(root.val - mi), Math.abs(root.val - ma));
    mi = Math.min(mi, root.val);
    ma = Math.max(ma, root.val);
    diff = Math.max(diff, dfs(root.left, mi, ma));
    diff = Math.max(diff, dfs(root.right, mi, ma));
    return diff;
}
