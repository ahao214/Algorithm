﻿var minOperations = function (nums) {
    let pre = nums[0] - 1, res = 0;
    for (const num of nums) {
        pre = Math.max(pre + 1, num);
        res += pre - num;
    }
    return res;
};