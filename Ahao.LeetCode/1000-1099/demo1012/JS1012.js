﻿var numDupDigitsAtMostN = function (n) {
    const sn = '' + n;
    dp = new Array(sn.length).fill(0).map(() => new Array(1 << 10).fill(-1));
    const f = (mask, sn, i, same) => {
        if (i === sn.length) {
            return 1;
        }
        if (!same && dp[i][mask] >= 0) {
            return dp[i][mask];
        }
        let res = 0, t = same ? (sn[i].charCodeAt() - '0'.charCodeAt()) : 9;
        for (let k = 0; k <= t; k++) {
            if ((mask & (1 << k)) !== 0) {
                continue;
            }
            res += f(mask === 0 && k === 0 ? mask : mask | (1 << k), sn, i + 1, same && k === t);
        }
        if (!same) {
            dp[i][mask] = res;
        }
        return res;
    };
    return n + 1 - f(0, sn, 0, true);
}


//组合数字
var numDupDigitsAtMostN = function (n) {
    const sn = '' + n;
    const f = (mask, sn, i, same) => {
        if (i === sn.length) {
            return 1;
        }
        let t = same ? sn[i].charCodeAt() - '0'.charCodeAt() : 9, res = 0, c = bitCount(mask) + 1;
        for (let k = 0; k <= t; k++) {
            if ((mask & (1 << k)) !== 0) {
                continue;
            }
            if (same && k === t) {
                res += f(mask | (1 << t), sn, i + 1, true);
            } else if (mask === 0 && k === 0) {
                res += f(0, sn, i + 1, false);
            } else {
                res += A(sn.length - 1 - i, 10 - c);
            }
        }
        return res;
    }
    return n + 1 - f(0, sn, 0, true);
}

const A = (x, y) => {
    let res = 1;
    for (let i = 0; i < x; i++) {
        res *= y--;
    }
    return res;
}

const bitCount = (n) => {
    return n.toString(2).split('0').join('').length;
}
