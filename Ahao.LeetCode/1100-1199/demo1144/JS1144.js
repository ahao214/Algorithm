﻿var movesToMakeZigzag = function (nums) {
    return Math.min(help(nums, 0), help(nums, 1));
}

const help = (nums, pos) => {
    let res = 0;
    for (let i = pos; i < nums.length; i += 2) {
        let a = 0;
        if (i - 1 >= 0) {
            a = Math.max(a, nums[i] - nums[i - 1] + 1);
        }
        if (i + 1 < nums.length) {
            a = Math.max(a, nums[i] - nums[i + 1] + 1);
        }
        res += a;
    }
    return res;
};
