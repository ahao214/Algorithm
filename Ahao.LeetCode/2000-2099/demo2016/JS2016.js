﻿var maximumDifference = function (nums) {
    const n = nums.length;
    let ans = -1,
        premin = nums[0];
    for (let i = 1; i < n; ++i) {
        if (nums[i] > premin) {
            ans = Math.max(ans, nums[i] - premin);
        } else {
            premin = nums[i];
        }
    }
    return ans;
};