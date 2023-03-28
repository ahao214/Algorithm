﻿var shortestCommonSupersequence = function(str1, str2) {
    const n = str1.length, m = str2.length;
    const dp = new Array(n + 1).fill(0).map(() => new Array(m + 1).fill(0));
    for (let i = 0; i < n; ++i) {
        dp[i][m] = n - i;
    }
    for (let i = 0; i < m; ++i) {
        dp[n][i] = m - i;
    }
    for (let i = n - 1; i >= 0; --i) {
        for (let j = m - 1; j >= 0; --j) {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = Math.min(dp[i + 1][j], dp[i][j + 1]) + 1;
            }
        }
    }
    let res = '';
    let t1 = 0, t2 = 0;
    while (t1 < n && t2 < m) {
        if (str1[t1] === str2[t2]) {
            res += str1[t1];
            ++t1;
            ++t2;
        } else if (dp[t1 + 1][t2] === dp[t1][t2] - 1) {
            res += str1[t1];
            ++t1;
        } else if (dp[t1][t2 + 1] === dp[t1][t2] - 1) {
            res += str2[t2];
            ++t2;
        }
    }
    if (t1 < n) {
        res += str1.slice(t1);
    } else if (t2 < m) {
        res += str2.slice(t2);
    }
    return res;
};