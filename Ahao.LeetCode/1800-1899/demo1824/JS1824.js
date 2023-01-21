﻿var minSideJumps = function (obstacles) {
    const n = obstacles.length - 1;
    const d = [1, 0, 1];
    for (let i = 1; i <= n; i++) {
        let minCnt = Number.MAX_VALUE;
        for (let j = 0; j < 3; j++) {
            if (j === obstacles[i] - 1) {
                d[j] = Number.MAX_VALUE;
            } else {
                minCnt = Math.min(minCnt, d[j]);
            }
        }
        for (let j = 0; j < 3; j++) {
            if (j == obstacles[i] - 1) {
                continue;
            }
            d[j] = Math.min(d[j], minCnt + 1);
        }
    }
    return _.min([d[0], d[1], d[2]]);
};
