var numRollsToTarget = function (n, k, target) {
    const mod = 1e9 + 7;
    f = new Array(n + 1).fill(0).map(() => new Array(target + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j <= target; j++) {
            for (let x = 1; x <= k; x++) {
                if (j - x >= 0) {
                    f[i][j] = (f[i][j] + f[i - 1][j - x]) % mod;
                }
            }
        }
    }
    return f[n][target];
};


var numRollsToTarget = function (n, k, target) {
    const mod = 1e9 + 7;
    f = new Array(target + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= n; i++) {
        g = new Array(target + 1).fill(0);
        for (let j = 0; j <= target; j++) {
            for (let x = 1; x <= k; x++) {
                if (j - x >= 0) {
                    g[j] = (g[j] + f[j - x]) % mod;
                }
            }
        }
        f = g;
    }
    return f[target];
};




var numRollsToTarget = function (n, k, target) {
    const mod = 1e9 + 7;
    f = new Array(target + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= n; i++) {
        for (let j = target; j >= 0; j--) {
            f[j] = 0;
            for (let x = 1; x <= k; x++) {
                if (j - x >= 0) {
                    f[j] = (f[j] + f[j - x]) % mod;
                }
            }
        }
    }
    return f[target];
};


