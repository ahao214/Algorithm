﻿var minimumTime = function (n, relations, time) {
    let res = 0;
    let prev = Array(n + 1).fill(0);
    for (let i = 0; i <= n; i++) {
        prev[i] = [];
    }
    for (var relation of relations) {
        let x = relation[0], y = relation[1];
        prev[y].push(x);
    }
    let memo = {};
    for (let i = 1; i <= n; i++) {
        res = Math.max(res, dp(i, time, prev, memo));
    }
    return res;
};

function dp(i, time, prev, memo) {
    if (!memo[i]) {
        let cur = 0;
        for (let p of prev[i]) {
            cur = Math.max(cur, dp(p, time, prev, memo));
        }
        cur += time[i - 1];
        memo[i] = cur;
    }
    return memo[i];
}
