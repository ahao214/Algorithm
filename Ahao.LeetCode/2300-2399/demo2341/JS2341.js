﻿var numberOfPairs = function(nums) {
    const cnt = new Map();
    let res = 0;
    for (const num of nums) {
        cnt.set(num, !(cnt.get(num) || false));
        if (!cnt.get(num)) {
            res++;
        }
    }
    return [res, nums.length - 2 * res];
};
