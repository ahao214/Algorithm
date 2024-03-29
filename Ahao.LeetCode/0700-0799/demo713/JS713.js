﻿//方法一：二分查找
var numSubarrayProductLessThanK = function (nums, k) {
    if (k === 0) {
        return 0;
    }
    const n = nums.length;
    const logPrefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        logPrefix[i + 1] = logPrefix[i] + Math.log(nums[i]);
    }
    const logk = Math.log(k);
    let ret = 0;
    for (let j = 0; j < n; j++) {
        let l = 0;
        let r = j + 1;
        let idx = j + 1;
        const val = logPrefix[j + 1] - logk + 1e-10;
        while (l <= r) {
            const mid = Math.floor((l + r) / 2);
            if (logPrefix[mid] > val) {
                idx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ret += j + 1 - idx;
    }
    return ret;
};


//方法二：滑动窗口
var numSubarrayProductLessThanK = function (nums, k) {
    let n = nums.length, ret = 0;
    let prod = 1, i = 0;
    for (let j = 0; j < n; j++) {
        prod *= nums[j];
        while (i <= j && prod >= k) {
            prod /= nums[i];
            i++;
        }
        ret += j - i + 1;
    }
    return ret;
};
