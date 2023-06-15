﻿var minNumberOfSemesters = function (n, relations, k) {
    const dp = new Array(1 << n).fill(Infinity);
    const need = new Array(1 << n).fill(0);
    for (const edge of relations) {
        need[(1 << (edge[1] - 1))] |= 1 << (edge[0] - 1);
    }
    dp[0] = 0;
    for (let i = 1; i < (1 << n); ++i) {
        need[i] = need[i & (i - 1)] | need[i & (-i)];
        if ((need[i] | i) !== i) {
            continue;
        }
        const valid = i ^ need[i];
        if (bitCount(valid) <= k) {
            dp[i] = Math.min(dp[i], dp[i ^ valid] + 1);
        } else {
            for (let sub = valid; sub; sub = (sub - 1) & valid) {
                if (bitCount(sub) <= k) {
                    dp[i] = Math.min(dp[i], dp[i ^ sub] + 1);
                }
            }
        }
    }
    return dp[(1 << n) - 1];
}

function bitCount(n) {
    let count = 0;
    while (n) {
        count++;
        n &= n - 1;
    }
    return count;
}