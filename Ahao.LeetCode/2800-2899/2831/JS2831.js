﻿var longestEqualSubarray = function (nums, k) {
    let n = nums.length;
    let pos = new Map();
    for (let i = 0; i < n; i++) {
        if (!pos.has(nums[i])) {
            pos.set(nums[i], []);
        }
        pos.get(nums[i]).push(i);
    }
    let ans = 0;
    for (let vec of pos.values()) {
        for (let i = 0, j = 0; i < vec.length; i++) {
            /* 缩小窗口，直到不同元素数量小于等于 k */
            while (vec[i] - vec[j] - (i - j) > k) {
                j++;
            }
            ans = Math.max(ans, i - j + 1);
        }
    }
    return ans;
};
