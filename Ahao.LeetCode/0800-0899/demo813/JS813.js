﻿var largestSumOfAverages = function (nums, k) {
    const n = nums.length;
    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    const dp = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    for (let i = 1; i <= n; i++) {
        dp[i][1] = prefix[i] / i;
    }
    for (let j = 2; j <= k; j++) {
        for (let i = j; i <= n; i++) {
            for (let x = j - 1; x < i; x++) {
                dp[i][j] = Math.max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
            }
        }
    }
    return dp[n][k];
};


var largestSumOfAverages = function (nums, k) {
    const n = nums.length;
    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    const dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        dp[i] = prefix[i] / i;
    }
    for (let j = 2; j <= k; j++) {
        for (let i = n; i >= j; i--) {
            for (let x = j - 1; x < i; x++) {
                dp[i] = Math.max(dp[i], dp[x] + (prefix[i] - prefix[x]) / (i - x));
            }
        }
    }
    return dp[n];
};
