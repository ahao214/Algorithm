﻿var numPairsDivisibleBy60 = function (time) {
    const cnt = new Array(60).fill(0);
    for (let t of time) {
        cnt[t % 60]++;
    }
    let res = 0;
    for (let i = 1; i < 30; i++) {
        res += cnt[i] * cnt[60 - i];
    }
    res += cnt[0] * (cnt[0] - 1) / 2 + cnt[30] * (cnt[30] - 1) / 2;
    return res;
}
