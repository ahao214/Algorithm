﻿var maxAbsoluteSum = function (nums) {
    let positiveMax = 0, negativeMin = 0;
    let positiveSum = 0, negativeSum = 0;
    for (let num of nums) {
        positiveSum += num
        positiveMax = Math.max(positiveMax, positiveSum)
        positiveSum = Math.max(0, positiveSum)
        negativeSum += num
        negativeMin = Math.min(negativeMin, negativeSum)
        negativeSum = Math.min(0, negativeSum)
    }
    return Math.max(positiveMax, -negativeMin)
};
