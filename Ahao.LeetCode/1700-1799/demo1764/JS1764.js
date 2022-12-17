﻿//贪心+双指针
var canChoose = function (groups, nums) {
    let i = 0;
    for (let k = 0; k < nums.length && i < groups.length;) {
        if (check(groups[i], nums, k)) {
            k += groups[i].length;
            i++;
        } else {
            k++;
        }
    }
    return i === groups.length;
}

const check = (g, nums, k) => {
    if (k + g.length > nums.length) {
        return false;
    }
    for (let j = 0; j < g.length; j++) {
        if (g[j] !== nums[k + j]) {
            return false;
        }
    }
    return true;
};


//KMP 匹配算法
var canChoose = function (groups, nums) {
    let k = 0;
    for (let i = 0; i < groups.length; i++) {
        k = find(nums, k, groups[i]);
        if (k == -1) {
            return false;
        }
        k += groups[i].length;
    }
    return true;
}

const find = (nums, k, g) => {
    let m = g.length, n = nums.length;
    if (k + g.length > nums.length) {
        return -1;
    }
    const pi = new Array(m).fill(0);
    for (let i = 1, j = 0; i < m; i++) {
        while (j > 0 && g[i] !== g[j]) {
            j = pi[j - 1];
        }
        if (g[i] === g[j]) {
            j++;
        }
        pi[i] = j;
    }
    for (let i = k, j = 0; i < n; i++) {
        while (j > 0 && nums[i] !== g[j]) {
            j = pi[j - 1];
        }
        if (nums[i] === g[j]) {
            j++;
        }
        if (j === m) {
            return i - m + 1;
        }
    }
    return -1;
};
