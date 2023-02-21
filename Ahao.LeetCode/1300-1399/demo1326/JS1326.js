﻿//动态规划
var minTaps = function (n, ranges) {
    const intervals = new Array(n + 1).fill(new Array());
    for (let i = 0; i <= n; i++) {
        const start = Math.max(0, i - ranges[i]);
        const end = Math.min(n, i + ranges[i]);
        intervals[i] = [start, end];
    }
    intervals.sort((a, b) => a[0] - b[0]);
    const dp = new Array(n + 1).fill(Number.MAX_VALUE);
    dp[0] = 0;
    for (const interval of intervals) {
        let start = interval[0], end = interval[1];
        if (dp[start] === Number.MAX_VALUE) {
            return -1;
        }
        for (let j = start; j <= end; j++) {
            dp[j] = Math.min(dp[j], dp[start] + 1);
        }
    }
    return dp[n];
};


//贪心算法
var minTaps = function (n, ranges) {
    const rightMost = new Array(n + 1).fill(0).map((_, i) => i);
    for (let i = 0; i <= n; i++) {
        const start = Math.max(0, i - ranges[i]);
        const end = Math.min(n, i + ranges[i]);
        rightMost[start] = Math.max(rightMost[start], end);
    }
    let last = 0, ret = 0, pre = 0;
    for (let i = 0; i < n; i++) {
        last = Math.max(last, rightMost[i]);
        if (i === last) {
            return -1;
        }
        if (i === pre) {
            ret++;
            pre = last;
        }
    }
    return ret;
};
