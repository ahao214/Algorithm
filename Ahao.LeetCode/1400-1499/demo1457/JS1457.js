﻿function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

var pseudoPalindromicPaths = function (root) {
    let counter = new Array(10).fill(0);
    return dfs(root, counter);
};

var dfs = function (root, counter) {
    if (!root) {
        return 0;
    }
    counter[root.val]++;
    let res = 0;
    if (!root.left && !root.right) {
        if (isPseudoPalindrome(counter)) {
            res = 1;
        }
    } else {
        res = dfs(root.left, counter) + dfs(root.right, counter);
    }
    counter[root.val]--;
    return res;
}

var isPseudoPalindrome = function (counter) {
    let odd = 0;
    for (value of counter) {
        if (value % 2 == 1) {
            odd++;
        }
    }
    return odd <= 1;
}
