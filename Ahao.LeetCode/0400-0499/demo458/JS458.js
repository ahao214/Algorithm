﻿//动态规划
var poorPigs = function (buckets, minutesToDie, minutesToTest) {
    if (buckets === 1) {
        return 0;
    }
    const combinations = new Array(buckets + 1).fill(0).map(() => new Array(buckets + 1).fill(0));
    combinations[0][0] = 1;
    const iterations = Math.floor(minutesToTest / minutesToDie);
    const f = new Array(buckets).fill(0).map(() => new Array(iterations + 1).fill(0));
    for (let i = 0; i < buckets; i++) {
        f[i][0] = 1;
    }
    for (let j = 0; j <= iterations; j++) {
        f[0][j] = 1;
    }
    for (let i = 1; i < buckets; i++) {
        combinations[i][0] = 1;
        combinations[i][i] = 1;
        for (let j = 1; j < i; j++) {
            combinations[i][j] = combinations[i - 1][j - 1] + combinations[i - 1][j];
        }
        for (let j = 1; j <= iterations; j++) {
            for (let k = 0; k <= i; k++) {
                f[i][j] += f[k][j - 1] * combinations[i][i - k];
            }
        }
        if (f[i][iterations] >= buckets) {
            return i;
        }
    }
    return 0;
};

//数学
var poorPigs2 = function (buckets, minutesToDie, minutesToTest) {
    const states = Math.floor(minutesToTest / minutesToDie) + 1;
    const pigs = Math.ceil(Math.log(buckets) / Math.log(states));
    return pigs;
};