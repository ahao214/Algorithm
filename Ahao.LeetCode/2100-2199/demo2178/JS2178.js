﻿var maximumEvenSplit = function (finalSum) {
    const res = [];
    if (finalSum % 2 > 0) {
        return res;
    }
    for (let i = 2; i <= finalSum; i += 2) {
        res.push(i);
        finalSum -= i;
    }
    res[res.length - 1] += finalSum;
    return res;
};
