var minDifficulty = function (jobDifficulty, d) {
    const n = jobDifficulty.length;
    if (n < d) {
        return -1;
    }
    const dp = new Array(d + 1).fill(0).map(() => new Array(n).fill(0x3f3f3f3f));
    let ma = 0;
    for (let i = 0; i < n; ++i) {
        ma = Math.max(ma, jobDifficulty[i]);
        dp[0][i] = ma;
    }
    for (let i = 1; i < d; ++i) {
        for (let j = i; j < n; ++j) {
            ma = 0;
            for (let k = j; k >= i; --k) {
                ma = Math.max(ma, jobDifficulty[k]);
                dp[i][j] = Math.min(dp[i][j], ma + dp[i - 1][k - 1]);
            }
        }
    }
    return dp[d - 1][n - 1];
};



var minDifficulty = function (jobDifficulty, d) {
    const n = jobDifficulty.length;
    if (n < d) {
        return -1;
    }
    let dp = new Array(n).fill(0);
    for (let i = 0, j = 0; i < n; ++i) {
        j = Math.max(j, jobDifficulty[i]);
        dp[i] = j;
    }
    for (let i = 1; i < d; ++i) {
        const ndp = new Array(n).fill(0x3f3f3f3f);
        for (let j = i; j < n; ++j) {
            let ma = 0;
            for (let k = j; k >= i; --k) {
                ma = Math.max(ma, jobDifficulty[k]);
                ndp[j] = Math.min(ndp[j], ma + dp[k - 1]);
            }
        }
        dp = ndp;
    }
    return dp[n - 1];
};
