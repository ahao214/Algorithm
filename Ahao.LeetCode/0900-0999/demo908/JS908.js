﻿var smallestRangeI = function (nums, k) {
    const minNum = _.min(nums);
    const maxNum = _.max(nums);
    return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;
};
