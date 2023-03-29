var countVowelStrings = function(n) {
    const dp = new Array(5).fill(1);
    for (let i = 1; i < n; i++) {
        for (let j = 1; j < 5; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return _.sum(dp);
};


//组合数字
var countVowelStrings = function (n) {
    return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
};

