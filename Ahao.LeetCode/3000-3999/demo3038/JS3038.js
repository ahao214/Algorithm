﻿var maxOperations = function (nums) {
    let n = nums.length, t = 0;
    for (let i = 1; i < n; i += 2) {
        if (nums[i] + nums[i - 1] != nums[1] + nums[0]) {
            break;
        }
        t++;
    }
    return t;
};
