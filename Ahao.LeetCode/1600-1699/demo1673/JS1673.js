﻿var mostCompetitive = function (nums, k) {
    const res = [];
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        while (res.length > 0 && n - i + res.length > k && res[res.length - 1] > nums[i]) {
            res.pop();
        }
        res.push(nums[i]);
    }
    res.length = k;
    return res;
};
