﻿var findMaxK = function (nums) {
    let k = -1;
    for (const x of nums) {
        for (const y of nums) {
            if (-x === y) {
                k = Math.max(k, x);
            }
        }
    }
    return k;
};
