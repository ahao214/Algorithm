﻿var ways = function (pizza, k) {
    const m = pizza.length, n = pizza[0].length, mod = 1_000_000_007;
    const apples = Array(m + 1).fill(0).map(() => Array(n + 1).fill(0));
    const dp = Array(k + 1).fill(0).map(() => Array(m + 1).fill(0).map(() => Array(n + 1).fill(0)));
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            apples[i][j] = apples[i][j + 1] + apples[i + 1][j] - apples[i + 1][j + 1] + (pizza[i].charAt(j) == 'A' ? 1 : 0);
            dp[1][i][j] = apples[i][j] > 0 ? 1 : 0;
        }
    }

    // 预处理
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            apples[i][j] = apples[i][j + 1] + apples[i + 1][j] - apples[i + 1][j + 1] + (pizza[i].charAt(j) == 'A' ? 1 : 0);
            dp[1][i][j] = apples[i][j] > 0 ? 1 : 0;
        }
    }

    for (let ki = 2; ki <= k; ki++) {
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                // 水平方向切
                for (let i2 = i + 1; i2 < m; i2++) {
                    if (apples[i][j] > apples[i2][j]) {
                        dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % mod;
                    }
                }
                // 垂直方向切
                for (let j2 = j + 1; j2 < n; j2++) {
                    if (apples[i][j] > apples[i][j2]) {
                        dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % mod;
                    }
                }
            }
        }
    }
    return dp[k][0][0];
};
