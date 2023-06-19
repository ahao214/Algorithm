﻿var connectTwoGroups = function (cost) {
    const size1 = cost.length;
    const size2 = cost[0].length;
    const m = 1 << size2;
    const dp = Array.from(Array(size1 + 1), () => new Array(m).fill(Number.MAX_SAFE_INTEGER / 2));

    dp[0][0] = 0;

    for (let i = 1; i <= size1; i++) {
        for (let s = 0; s < m; s++) {
            for (let k = 0; k < size2; k++) {
                if ((s & (1 << k)) === 0) {
                    continue;
                }
                dp[i][s] = Math.min(dp[i][s], dp[i][s ^ (1 << k)] + cost[i - 1][k]);
                dp[i][s] = Math.min(dp[i][s], dp[i - 1][s] + cost[i - 1][k]);
                dp[i][s] = Math.min(dp[i][s], dp[i - 1][s ^ (1 << k)] + cost[i - 1][k]);
            }
        }
    }

    return dp[size1][m - 1];
};
