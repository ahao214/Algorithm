﻿//方法一：枚举每一个数
const check = [0, 0, 1, -1, -1, 1, 1, -1, 0, 1];
var rotatedDigits = function (n) {
    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        const num = '' + i;
        let valid = true, diff = false;
        for (let j = 0; j < num.length; ++j) {
            const ch = num[j];
            if (check[ch.charCodeAt() - '0'.charCodeAt()] === -1) {
                valid = false;
            } else if (check[ch.charCodeAt() - '0'.charCodeAt()] === 1) {
                diff = true;
            }
        }
        if (valid && diff) {
            ++ans;
        }
    }
    return ans;
};


//方法二：数位动态规划
var rotatedDigits = function (n) {
    const check = [0, 0, 1, -1, -1, 1, 1, -1, 0, 1];
    const memo = new Array(5).fill(0).map(() => new Array(2).fill(0).map(() => new Array(2).fill(-1)));
    let digits = [];

    const dfs = (pos, bound, diff) => {
        if (pos === digits.length) {
            return diff;
        }
        if (memo[pos][bound][diff] !== -1) {
            return memo[pos][bound][diff];
        }

        let ret = 0;
        for (let i = 0; i <= (bound !== 0 ? digits[pos] : 9); ++i) {
            if (check[i] != -1) {
                ret += dfs(
                    pos + 1,
                    bound !== 0 && i === digits[pos] ? 1 : 0,
                    diff !== 0 || check[i] === 1 ? 1 : 0
                );
            }
        }
        return memo[pos][bound][diff] = ret;
    }

    while (n !== 0) {
        digits.push(n % 10);
        n = Math.floor(n / 10);
    }
    digits = _.reverse(digits);

    const ans = dfs(0, 1, 0);
    return ans;
};


