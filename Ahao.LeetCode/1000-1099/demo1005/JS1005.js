﻿/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestSumAfterKNegations = function (nums, k) {
    const freq = new Map();
    for (const num of nums) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    let ans = _.sum(nums);
    for (let i = -100; i < 0; ++i) {
        if (freq.has(i)) {
            const ops = Math.min(k, freq.get(i));
            ans += (-i) * ops * 2;
            freq.set(i, freq.get(i) - ops);
            freq.set(-i, (freq.get(-i) || 0) + ops);
            k -= ops;
            if (k === 0) {
                break;
            }
        }
    }
    if (k > 0 && k % 2 === 1 && !freq.has(0)) {
        for (let i = 1; i <= 100; ++i) {
            if (freq.has(i)) {
                ans -= i * 2;
                break;
            }
        }
    }
    return ans;
};