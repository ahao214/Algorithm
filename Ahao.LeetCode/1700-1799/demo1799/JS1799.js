﻿var maxScore = function (nums) {
    const m = nums.length;
    const dp = new Array(1 << m).fill(0);
    const gcdTmp = new Array(m).fill(0).map(() => new Array(m).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = i + 1; j < m; ++j) {
            gcdTmp[i][j] = gcd(nums[i], nums[j]);
        }
    }
    let all = 1 << m;
    for (let s = 1; s < all; ++s) {
        let t = bitCount(s);
        if ((t & 1) !== 0) {
            continue;
        }
        for (let i = 0; i < m; ++i) {
            if (((s >> i) & 1) !== 0) {
                for (let j = i + 1; j < m; ++j) {
                    if (((s >> j) & 1) !== 0) {
                        dp[s] = Math.max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + Math.floor(t / 2) * gcdTmp[i][j]);
                    }
                }
            }
        }
    }
    return dp[all - 1];
}

const gcd = (num1, num2) => {
    while (num2 !== 0) {
        const temp = num1;
        num1 = num2;
        num2 = temp % num2;
    }
    return num1;
};

const bitCount = (n) => {
    return n.toString(2).split('0').join('').length;
}
