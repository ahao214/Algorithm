﻿var sumOfPower = function (nums) {
    let n = nums.length;
    nums.sort((a, b) => a - b);
    let dp = 0, preSum = 0;
    let res = 0, mod = 1e9 + 7;
    for (let i = 0; i < n; i++) {
        dp = (nums[i] + preSum) % mod;
        preSum = (preSum + dp) % mod;
        res = (res + Number(BigInt(nums[i]) * BigInt(nums[i]) * BigInt(dp) % BigInt(mod))) % mod;
    }
    return res;
};

