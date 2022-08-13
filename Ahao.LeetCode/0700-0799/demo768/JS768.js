﻿var maxChunksToSorted = function (arr) {
    const cnt = new Map();
    let res = 0;
    const sortedArr = new Array(arr.length).fill(0);
    sortedArr.splice(0, arr.length, ...arr);
    sortedArr.sort((a, b) => a - b);
    for (let i = 0; i < sortedArr.length; i++) {
        const x = arr[i], y = sortedArr[i];
        cnt.set(x, (cnt.get(x) || 0) + 1);
        if (cnt.get(x) === 0) {
            cnt.delete(x);
        }
        cnt.set(y, (cnt.get(y) || 0) - 1);
        if (cnt.get(y) === 0) {
            cnt.delete(y);
        }
        if (cnt.size === 0) {
            res++;
        }
    }
    return res;
};
