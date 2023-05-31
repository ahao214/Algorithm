﻿var mctFromLeafValues = function (arr) {
    const n = arr.length;
    const dp = Array(n).fill(0).map(() => Array(n).fill(Infinity));
    const mval = Array(n).fill(0).map(() => Array(n));
    for (let j = 0; j < n; j++) {
        mval[j][j] = arr[j];
        dp[j][j] = 0;
    }
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            mval[i][j] = Math.max(arr[i], mval[i + 1][j]);
            for (let k = i; k < j; k++) {
                dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}