var maxSatisfaction = function (satisfaction) {
    const n = satisfaction.length;
    const dp = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    satisfaction.sort((a, b) => a - b);
    let res = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + satisfaction[i - 1] * j;
            if (j < i) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
            }
            res = Math.max(res, dp[i][j])
        }
    }
    return res;
};




var maxSatisfaction = function (satisfaction) {
    satisfaction.sort((a, b) => b - a);
    let presum = 0, ans = 0;
    for (si of satisfaction) {
        if (presum + si > 0) {
            presum += si;
            ans += presum;
        } else {
            break;
        }
    }
    return ans;
};
