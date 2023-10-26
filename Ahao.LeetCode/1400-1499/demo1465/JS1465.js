﻿var maxArea = function (h, w, horizontalCuts, verticalCuts) {
    const mod = 1e9 + 7;
    horizontalCuts.sort((a, b) => a - b);
    verticalCuts.sort((a, b) => a - b);
    var calMax = function (arr, boardr) {
        let res = 0, pre = 0;
        for (let i = 0; i < arr.length; i++) {
            res = Math.max(arr[i] - pre, res);
            pre = arr[i];
        }
        return Math.max(res, boardr - pre);
    }
    return BigInt(calMax(horizontalCuts, h)) * BigInt(calMax(verticalCuts, w)) % BigInt(mod);
};