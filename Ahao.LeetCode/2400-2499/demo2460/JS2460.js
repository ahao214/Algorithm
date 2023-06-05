﻿var applyOperations = function (nums) {
    let n = nums.length;
    let j = 0;
    for (let i = 0; i < n; i++) {
        if (i + 1 < n && nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
        if (nums[i] != 0) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            j++;
        }
    }
    return nums;
};