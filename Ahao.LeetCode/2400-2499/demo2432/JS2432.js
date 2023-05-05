﻿var hardestWorker = function (n, logs) {
    let ans = logs[0][0], maxCost = logs[0][1];
    for (let i = 1; i < logs.length; i++) {
        const idx = logs[i][0];
        const cost = logs[i][1] - logs[i - 1][1];
        if (cost > maxCost || (cost === maxCost && idx < ans)) {
            ans = idx;
            maxCost = cost;
        }
    }
    return ans;
};
