﻿var mostFrequentEven = function(nums) {
    let count = new Map();
    for (let x of nums) {
        if (x % 2 == 0) {
            count.set(x, (count.get(x) || 0) + 1);
        }
    }
    let res = -1, ct = 0;
    for (let [k, v] of count) {
        if (res == -1 || v > ct || v == ct && k < res) {
            res = k;
            ct = v;
        }
    }
    return res;
};